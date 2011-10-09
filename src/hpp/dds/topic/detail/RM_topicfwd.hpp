#ifndef OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_
#define OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_

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

#include <idds/topic/topicfwd.hpp>


namespace dds { namespace topic {

namespace detail {
    typedef idds::topic::BuiltinTopicKeyImpl
    BuiltinTopicKeyImpl;

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
    template <typename T>
    class ContentFilteredTopic;
#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
    template <typename T>
    class MultiTopic;
#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

    typedef idds::topic::ParticipantBuiltinTopicDataImpl
    ParticipantBuiltinTopicDataImpl;

    typedef idds::topic::PublicationBuiltinTopicDataImpl
    PublicationBuiltinTopicDataImpl;

    typedef idds::topic::SubscriptionBuiltinTopicDataImpl
    SubscriptionBuiltinTopicDataImpl;

    typedef idds::topic::TopicBuiltinTopicDataImpl
    TopicBuiltinTopicDataImpl;

    template <typename T>
    class Topic;
}   // namespace dds::topic::detail


namespace qos { namespace detail {
    typedef tdds::core::qos::EntityQos<idds::qos::TopicQosImpl> TopicQos;
} } // namespace dds::topic::qos::detail

} }

#endif /* OMG_DDS_TOPIC_DETAIL_TOPIC_FWD_HPP_ */
