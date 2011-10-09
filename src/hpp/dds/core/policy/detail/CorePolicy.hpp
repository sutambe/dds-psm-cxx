#ifndef OMG_DDS_QOS_DETAIL_CORE_POLICY_HPP_
#define OMG_DDS_QOS_DETAIL_CORE_POLICY_HPP_

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

#include <idds/core/policy/CorePolicy.hpp>
#include <dds/core/policy/TCorePolicy.hpp>


namespace dds { namespace core { namespace policy { namespace detail {
#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    typedef dds::core::policy::TDataRepresentation<idds::core::policy::DataRepresentation>
    DataRepresentation;
#endif // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    
    typedef dds::core::policy::TDeadline<idds::core::policy::Deadline>
    Deadline;
    
    typedef dds::core::policy::TDestinationOrder<idds::core::policy::DestinationOrder>
    DestinationOrder;
    
    typedef dds::core::policy::TDurability<idds::core::policy::Durability>
    Durability;
    
#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    typedef dds::core::policy::TDurabilityService<idds::core::policy::DurabilityService>
    DurabilityService;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT
    
    typedef dds::core::policy::TEntityFactory<idds::core::policy::EntityFactory>
    EntityFactory;
    
    typedef dds::core::policy::TGroupData<idds::core::policy::GroupData>
    GroupData;
    
    typedef dds::core::policy::THistory<idds::core::policy::History>
    History;
    
    typedef dds::core::policy::TLatencyBudget<idds::core::policy::LatencyBudget>
    LatencyBudget;
    
    typedef dds::core::policy::TLifespan<idds::core::policy::Lifespan>
    Lifespan;
    
    typedef dds::core::policy::TLiveliness<idds::core::policy::Liveliness>
    Liveliness;
    
    typedef dds::core::policy::TOwnership<idds::core::policy::Ownership>
    Ownership;
    
#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    typedef dds::core::policy::TOwnershipStrength<idds::core::policy::OwnershipStrength>
    OwnershipStrength;
#endif  // OMG_DDS_OWNERSHIP_SUPPORT
    
    typedef dds::core::policy::TPartition<idds::core::policy::Partition>
    Partition;
    
    typedef dds::core::policy::TPresentation<idds::core::policy::Presentation>
    Presentation;
        
    typedef dds::core::policy::TReaderDataLifecycle<idds::core::policy::ReaderDataLifecycle>
    ReaderDataLifecycle;
    
    typedef dds::core::policy::TReliability<idds::core::policy::Reliability>
    Reliability;
    
    typedef dds::core::policy::TResourceLimits<idds::core::policy::ResourceLimits>
    ResourceLimits;
    
    typedef dds::core::policy::TTimeBasedFilter<idds::core::policy::TimeBasedFilter>
    TimeBasedFilter;
    
    typedef dds::core::policy::TTopicData<idds::core::policy::TopicData>
    TopicData;
    
    typedef dds::core::policy::TTransportPriority<idds::core::policy::TransportPriority>
    TransportPriority;
    
#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    typedef dds::core::policy::TTypeConsistencyEnforcement<idds::core::policy::TypeConsistencyEnforcement>
    TypeConsistencyEnforcement;
#endif // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    
    typedef dds::core::policy::TUserData<idds::core::policy::UserData>
    UserData;
    
    typedef dds::core::policy::TWriterDataLifecycle<idds::core::policy::WriterDataLifecycle>
    WriterDataLifecycle;
} } } } // namespace dds::core::policy::detail


#endif /* OMG_DDS_QOS_DETAIL_CORE_POLICY_HPP_ */
