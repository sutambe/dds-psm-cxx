#ifndef OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_

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

#include <string>

#include <dds/core/status/Status.hpp>
#include <dds/topic/detail/AnyTopicDescription.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <dds/domain/DomainParticipant.hpp>


namespace dds { namespace topic { namespace detail {

class THolderBase : public virtual TDHolderBase {
public:
    virtual ~THolderBase() { }

    virtual const dds::core::status::InconsistentTopicStatus inconsistent_topic_status()  = 0;

    virtual const dds::topic::qos::TopicQos qos() const = 0;

    virtual void qos(const dds::topic::qos::TopicQos& qos) = 0;
};

template <typename T>
class THolder : public TDHolder<T>, public THolderBase {
public:
    THolder(const T& t) : TDHolder<T>(t) { }
    virtual ~THolder() { }
public:
    virtual const dds::core::status::InconsistentTopicStatus inconsistent_topic_status();

    virtual const dds::topic::qos::TopicQos qos() const;

    virtual void qos(const dds::topic::qos::TopicQos& qos);
};
} } }

#endif /* OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_ */
