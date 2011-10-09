#ifndef OMG_IDDS_TOPIC_BUILT_IN_TOPIC_HPP_
#define OMG_IDDS_TOPIC_BUILT_IN_TOPIC_HPP_

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

#include <dds/core/detail/conformance.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <dds/topic/BuiltinTopicKey.hpp>

namespace idds { namespace topic {
    class ParticipantBuiltinTopicDataImpl;
    class TopicBuiltinTopicDataImpl;
    class PublicationBuiltinTopicDataImpl;
    class SubscriptionBuiltinTopicDataImpl;
} }
    
class idds::topic::ParticipantBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const ::dds::core::policy::UserData& user_data() {
        return user_data_;
    }
protected:
    dds::topic::BuiltinTopicKey key_;
    ::dds::core::policy::UserData user_data_;
};

class idds::topic::TopicBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }
    const std::string&                  name() const {
        return name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return durability_service_;
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }
    const ::dds::core::policy::TransportPriority&  transport_priority() const {
        return transport_priority_;
    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return lifespan_;
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }
    const ::dds::core::policy::History&            history() const {
        return history_;
    }
    const ::dds::core::policy::ResourceLimits&     resource_limits() const {
        return resource_limits_;
    }
    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }
    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

protected:
    dds::topic::BuiltinTopicKey  key_;
    std::string                  name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    ::dds::core::policy::DurabilityService  durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::TransportPriority  transport_priority_;
    ::dds::core::policy::Lifespan           lifespan_;
    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::History            history_;
    ::dds::core::policy::ResourceLimits     resource_limits_;
    ::dds::core::policy::Ownership          ownership_;
    ::dds::core::policy::TopicData          topic_data_;
};

//==============================================================================
//            PublicationBuiltinTopicDataImpl
//==============================================================================

class idds::topic::PublicationBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const dds::topic::BuiltinTopicKey& participant_key() {
        return participant_key_;
    }

    const std::string&                  topic_name() const {
        return topic_name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

    const ::dds::core::policy::DurabilityService&  durability_service() const {
        return durability_service_;
    }

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }
//    const dds::core::policy::TransportPriority&  transport_priority() const {
//        return transport_priority_;
//    }
    const ::dds::core::policy::Lifespan&           lifespan() const {
        return lifespan_;
    }
    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }

    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }


#ifdef  OMG_DDS_OWNERSHIP_SUPPORT

    const ::dds::core::policy::OwnershipStrength&  ownership_strength() const {
        return ownership_strength_;
    }

#endif  // OMG_DDS_OWNERSHIP_SUPPORT


    const ::dds::core::policy::Partition&          partition() const {
        return partition_;
    }
    const ::dds::core::policy::Presentation&       presentation() const {
        return presentation_;
    }

    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

    const ::dds::core::policy::UserData&           user_data() const {
        return user_data_;
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return group_data_;
    }

public:
    dds::topic::BuiltinTopicKey  key_;
    dds::topic::BuiltinTopicKey  participant_key_;
    std::string                  topic_name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    ::dds::core::policy::DurabilityService  durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::Lifespan           lifespan_;
    ::dds::core::policy::UserData            user_data_;
    ::dds::core::policy::Ownership          ownership_;

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    ::dds::core::policy::OwnershipStrength  ownership_strength_;
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::Presentation       presentation_;
    ::dds::core::policy::Partition          partition_;
    ::dds::core::policy::TopicData           topic_data_;
    ::dds::core::policy::GroupData          group_data_;
};

//==============================================================================
//            SubscriptionBuiltinTopicDataImpl
//==============================================================================

class idds::topic::SubscriptionBuiltinTopicDataImpl {
public:
    const dds::topic::BuiltinTopicKey& key() {
        return key_;
    }

    const dds::topic::BuiltinTopicKey& participant_key() {
        return participant_key_;
    }

    const std::string&                  topic_name() const {
        return topic_name_;
    }
    const std::string&                  type_name() const {
        return type_name_;
    }
    const ::dds::core::policy::Durability&         durability() const {
        return durability_;
    }


    const ::dds::core::policy::Deadline&           deadline() const {
        return deadline_;
    }
    const ::dds::core::policy::LatencyBudget&      latency_budget() const {
        return latency_budget_;
    }
    const ::dds::core::policy::Liveliness&         liveliness() const {
        return liveliness_;
    }
    const ::dds::core::policy::Reliability&        reliability() const {
        return reliability_;
    }


    const ::dds::core::policy::DestinationOrder&   destination_order() const {
        return destination_order_;
    }

    const ::dds::core::policy::TimeBasedFilter& time_based_filter() {
        return time_based_filter_;
    }

    const ::dds::core::policy::Ownership&          ownership() const {
        return ownership_;
    }
    const ::dds::core::policy::TopicData&          topic_data() const {
        return topic_data_;
    }

    const ::dds::core::policy::Partition&          partition() const {
        return partition_;
    }
    const ::dds::core::policy::Presentation&       presentation() const {
        return presentation_;
    }

    const ::dds::core::policy::UserData&           user_data() const {
        return user_data_;
    }

    const ::dds::core::policy::GroupData&          group_data() const {
        return group_data_;
    }

public:
    dds::topic::BuiltinTopicKey  key_;
    dds::topic::BuiltinTopicKey  participant_key_;
    std::string                  topic_name_;
    std::string                  type_name_;
    ::dds::core::policy::Durability         durability_;
    ::dds::core::policy::Deadline           deadline_;
    ::dds::core::policy::LatencyBudget      latency_budget_;
    ::dds::core::policy::Liveliness         liveliness_;
    ::dds::core::policy::Reliability        reliability_;
    ::dds::core::policy::Ownership          ownership_;
    ::dds::core::policy::DestinationOrder   destination_order_;
    ::dds::core::policy::UserData           user_data_;
    ::dds::core::policy::TimeBasedFilter    time_based_filter_;
    ::dds::core::policy::Presentation       presentation_;
    ::dds::core::policy::Partition          partition_;
    ::dds::core::policy::TopicData          topic_data_;
    ::dds::core::policy::GroupData         group_data_;
};
#endif /* OMG_IDDS_TOPIC_BUILT_IN_TOPIC_HPP_ */
