#ifndef OMG_TDDS_SUB_SUBSCRIBER_HPP_
#define OMG_TDDS_SUB_SUBSCRIBER_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dds/core/TEntity.hpp>
#include <dds/core/cond/StatusCondition.hpp>
#include <dds/domain/DomainParticipant.hpp>

namespace dds { namespace sub {
    template <typename DELEGATE>
    class TSubscriber;
    
    class SubscriberListener;
} }

template <typename DELEGATE>
class dds::sub::TSubscriber : public dds::core::TEntity<DELEGATE> {
public:
	OMG_DDS_REF_TYPE(TSubscriber, dds::core::TEntity, DELEGATE)

public:
    typedef dds::sub::SubscriberListener                 Listener;
    typedef dds::core::cond::StatusCondition<TSubscriber> StatusCondition;

public:
    TSubscriber(const ::dds::domain::DomainParticipant& dp) 
    : dds::core::TEntity<DELEGATE>(new DELEGATE(dp,
                                                dp.default_subscriber_qos(),
                                                0,
                                                dds::core::status::StatusMask::all())) { }
    
    TSubscriber(const ::dds::domain::DomainParticipant& dp,
                const dds::sub::qos::SubscriberQos& qos,
                dds::sub::SubscriberListener* listener = NULL,
                const dds::core::status::StatusMask& mask = dds::core::status::StatusMask::all()) 
    : dds::core::TEntity<DELEGATE>(new DELEGATE(dp,
                                      qos,
                                      listener,
                                      mask)) { }
    
public:
	~TSubscriber() {}
public:
    /**
     * This operation allows access to the StatusCondition
     * (Section 7.1.2.1.9, “StatusCondition Class) associated with the Entity.
     * The returned condition can then be added to a WaitSet (Section 7.1.2.1.6,
     * WaitSet Class) so that the application can wait for specific status changes
     * that affect the Entity.
     *
     * @return the status condition
     */
    StatusCondition status_condition() const{
        return this->delegate()->template status_condition<TSubscriber>(*this);
    }

public:
	/**
	 * This operation invokes the operation on_data_available on the
	 * DataReaderListener objects attached to contained DataReader
	 * entities with a DATA_AVAILABLE status that is considered changed
	 * as described in Section 7.1.4.2.2, Changes in Read Communication
	 * Statuses.
	 */
	void notify_datareaders() {
		this->delegate()->notify_datareaders();
	}

    void listener(Listener*,
                  const dds::core::status::StatusMask& event_mask);

    Listener* listener() const;


	const dds::sub::qos::SubscriberQos qos() const {
		return this->delegate()->qos();
	}

	void qos(const dds::sub::qos::SubscriberQos& the_qos) {
		this->delegate()->qos(the_qos);
	}
    
    const dds::sub::qos::DataReaderQos default_datareader_qos() const;
    void default_datareader_qos(const dds::sub::qos::DataReaderQos &qos);
};


#endif /* OMG_TDDS_SUB_SUBSCRIBER_HPP_ */
