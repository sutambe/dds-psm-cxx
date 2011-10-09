#ifndef OMG_IDDS_QOS_DATA_READER_QOS_IMPL_HPP_
#define OMG_IDDS_QOS_DATA_READER_QOS_IMPL_HPP_

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

namespace idds { namespace qos {

class DataReaderQosImpl {
public:
    DataReaderQosImpl();

    DataReaderQosImpl(::dds::core::policy::UserData               user_data,
            ::dds::core::policy::Durability              durability,

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
            ::dds::core::policy::DurabilityService       durability_service,
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

            ::dds::core::policy::Deadline       deadline,
            ::dds::core::policy::LatencyBudget  budget,
            ::dds::core::policy::Liveliness     liveliness,
            ::dds::core::policy::Reliability             reliability,
            ::dds::core::policy::DestinationOrder        order,
            ::dds::core::policy::History                 history,
            ::dds::core::policy::ResourceLimits          resources,
            ::dds::core::policy::TransportPriority       priority,
            ::dds::core::policy::Lifespan                lifespan,
            ::dds::core::policy::Ownership               ownership,
            ::dds::core::policy::TimeBasedFilter         tfilter,
            ::dds::core::policy::ReaderDataLifecycle     lifecycle);

    ~DataReaderQosImpl();


    void policy(const ::dds::core::policy::UserData&            user_data);
    void policy(const ::dds::core::policy::Durability&          durability);

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    void policy(const ::dds::core::policy::DurabilityService&   durability_service);
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    void policy(const ::dds::core::policy::Deadline&            deadline);
    void policy(const ::dds::core::policy::LatencyBudget&       budget);
    void policy(const ::dds::core::policy::Liveliness&          liveliness);
    void policy(const ::dds::core::policy::Reliability&         reliability);
    void policy(const ::dds::core::policy::DestinationOrder&    order);
    void policy(const ::dds::core::policy::History&             history);
    void policy(const ::dds::core::policy::ResourceLimits&      resources);
    void policy(const ::dds::core::policy::TransportPriority&   priority);
    void policy(const ::dds::core::policy::Lifespan&            lifespan);
    void policy(const ::dds::core::policy::Ownership&           ownership);
    void policy(const ::dds::core::policy::TimeBasedFilter&     tfilter);
    void policy(const ::dds::core::policy::ReaderDataLifecycle& lifecycle);

    template <typename P> const P& policy() const;
    template <typename P> P& policy();

private:
    ::dds::core::policy::UserData               user_data_;
    ::dds::core::policy::Durability              durability_;

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
    ::dds::core::policy::DurabilityService       durability_service_;
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

    ::dds::core::policy::Deadline                deadline_;
    ::dds::core::policy::LatencyBudget           budget_;
    ::dds::core::policy::Liveliness              liveliness_;
    ::dds::core::policy::Reliability             reliability_;
    ::dds::core::policy::DestinationOrder        order_;
    ::dds::core::policy::History                 history_;
    ::dds::core::policy::ResourceLimits          resources_;
    ::dds::core::policy::TransportPriority       priority_;
    ::dds::core::policy::Lifespan                lifespan_;
    ::dds::core::policy::Ownership               ownership_;
    ::dds::core::policy::TimeBasedFilter         tfilter_;
    ::dds::core::policy::ReaderDataLifecycle     lifecycle_;

};

}}
#endif /* OMG_IDDS_QOS_DATA_READER_QOS_IMPL_HPP_ */
