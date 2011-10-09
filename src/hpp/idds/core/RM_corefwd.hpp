#ifndef OMG_IDDS_CORE_CORE_FWD_HPP_
#define OMG_IDDS_CORE_CORE_FWD_HPP_

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


namespace idds { namespace core {

class ConditionImpl;

class EntityImpl;

class FunctorHolder;

class GuardConditionImpl;

class InconsistentTopicStatusImpl;

class InstanceHandleImpl;

class LivelinessChangedStatusImpl;

class LivelinessLostStatusImpl;

class OfferedDeadlineMissedStatusImpl;

class OfferedIncompatibleQosStatusImpl;

template <typename Functor, typename ARG1>
class OneArgFunctorHolder;

class PublicationMatchedStatusImpl;

class RequestedDeadlineMissedStatusImpl;

class RequestedIncompatibleQosStatusImpl;

class SampleLostStatusImpl;

class SampleRejectedStatusImpl;

class SubscriptionMatchedStatusImpl;

template <typename Functor, typename ARG1, typename ARG2>
class TwoArgFunctorHolder;

template <typename Functor>
class VoidFunctorHolder;


namespace policy {
#ifdef  OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    class DataRepresentation;
#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

    class Deadline;

    class DestinationOrder;

    class Durability;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    class DurabilityService;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    class EntityFactory;

    class GroupData;

    class History;

    class LatencyBudget;

    class Lifespan;

    class Liveliness;

    class Ownership;

#ifdef  OMG_DDS_OWNERSHIP_SUPPORT
    class OwnershipStrength;
#endif  // OMG_DDS_OWNERSHIP_SUPPORT

    class Partition;

    class Presentation;

    class QosPolicyCountImpl;

    class ReaderDataLifecycle;

    class Reliability;

    class ResourceLimits;

    class TimeBasedFilter;

    class TopicData;

    class TransportPriority;

#ifdef  OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT
    class TypeConsistencyEnforcement;
#endif  // OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

    class UserData;

    class WriterDataLifecycle;
}

} }

#endif /* OMG_IDDS_CORE_CORE_FWD_HPP_ */
