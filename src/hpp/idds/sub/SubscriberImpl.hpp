#ifndef IDDS_SUB_SUBSCRIBER_IMPL_HPP_
#define IDDS_SUB_SUBSCRIBER_IMPL_HPP_

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

#include <idds/core/EntityImpl.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/core/status/State.hpp>
#include <dds/core/cond/StatusCondition.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>


namespace idds { namespace sub {

class SubscriberImpl : public idds::core::EntityImpl {
public:

public:
    inline SubscriberImpl(const dds::domain::DomainParticipant& dp,
                          const dds::sub::qos::SubscriberQos& the_qos,
                          dds::sub::SubscriberListener* the_listener,
                          const dds::core::status::StatusMask& event_mask)
    : dp_(dp),
      qos_(the_qos),
      listener_(the_listener),
      mask_(event_mask)
    { }

	~SubscriberImpl() {}

public:
    /**
     * Returns a <code>StatusCondition</code> instance associated with
     * this <code>Entity</code>.
     */
    template <typename SELF>
    ::dds::core::cond::StatusCondition<SELF>
    status_condition(const SELF& self) const {
        return ::dds::core::cond::StatusCondition<SELF>(
                new dds::core::cond::detail::StatusCondition<SELF>(self));
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

	}

	const dds::domain::DomainParticipant& parent() const {
        return dp_;
	}

	const dds::sub::qos::SubscriberQos qos() const {
            return dds::sub::qos::SubscriberQos();
	}

	void qos(const dds::sub::qos::SubscriberQos& the_qos) {
            // implementation-defined
	}

private:
    dds::domain::DomainParticipant dp_;
    dds::sub::qos::SubscriberQos qos_;
    dds::sub::SubscriberListener* listener_;
    dds::core::status::StatusMask mask_;
};

}}
#endif /* IDDS_SUB_SUBSCRIBER_IMPL_HPP_ */


