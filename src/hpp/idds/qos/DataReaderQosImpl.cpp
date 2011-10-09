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

#include <idds/qos/DataReaderQosImpl.hpp>


idds::qos::DataReaderQosImpl::DataReaderQosImpl() {  }

idds::qos::DataReaderQosImpl::DataReaderQosImpl(
        dds::core::policy::UserData               user_data,
        dds::core::policy::Durability              durability,

#ifdef  OMG_DDS_PERSISTENCE_SUPPORT
        dds::core::policy::DurabilityService       durability_service,
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

        dds::core::policy::Deadline       deadline,
        dds::core::policy::LatencyBudget  budget,
        dds::core::policy::Liveliness     liveliness,
        dds::core::policy::Reliability             reliability,
        dds::core::policy::DestinationOrder        order,
        dds::core::policy::History                 history,
        dds::core::policy::ResourceLimits          resources,
        dds::core::policy::TransportPriority       priority,
        dds::core::policy::Lifespan                lifespan,
        dds::core::policy::Ownership               ownership,
        dds::core::policy::TimeBasedFilter         tfilter,
        dds::core::policy::ReaderDataLifecycle     lifecycle)
: user_data_(user_data),
  durability_(durability),

#ifdef OMG_DDS_PERSISTENCE_SUPPORT
  durability_service_(durability_service),
#endif  // OMG_DDS_PERSISTENCE_SUPPORT

  deadline_(deadline),
  budget_(budget),
  liveliness_(liveliness),
  reliability_(reliability),
  order_(order),
  history_(history),
  resources_(resources),
  priority_(priority),
  lifespan_(lifespan),
  ownership_(ownership),
  tfilter_(tfilter),
  lifecycle_(lifecycle) {}

idds::qos::DataReaderQosImpl::~DataReaderQosImpl() { }

void
idds::qos::DataReaderQosImpl::policy(const dds::core::policy::UserData& user_data) {
    user_data_ = user_data;
}

void
idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Durability& durability) {
    durability_ = durability;
}


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::DurabilityService& durability_service) {
    durability_service_ = durability_service;
}

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Deadline& deadline) {
    deadline_ = deadline;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::LatencyBudget&  budget) {
    budget_ = budget;
}


void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Liveliness& liveliness) {
    liveliness_ = liveliness;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Reliability& reliability) {
    reliability_ = reliability;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::DestinationOrder& order) {
    order_ = order;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::History& history) {
    history_ = history;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::ResourceLimits& resources) {
    resources_ = resources;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::TransportPriority& priority) {
    priority_ = priority;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Lifespan& lifespan) {
    lifespan_ = lifespan;
}

void idds::qos::DataReaderQosImpl::policy(const dds::core::policy::Ownership& ownership) {
    ownership_ = ownership;
}

void
idds::qos::DataReaderQosImpl::policy(const dds::core::policy::TimeBasedFilter& tfilter) {
    tfilter_ = tfilter;
}
void
idds::qos::DataReaderQosImpl::policy(const dds::core::policy::ReaderDataLifecycle& lifecycle) {
    lifecycle_ = lifecycle;
}

//
//template<>
//const dds::core::policy::UserData&
//idds::qos::DataReaderQosImpl::policy<dds::core::policy::UserData>() const {
//    return user_data_;
//}

//template <>
//const int&
//idds::qos::DataReaderQosImpl::policy<int>() const {
//    return 0;
//}

namespace idds { namespace qos {

template<>
const ::dds::core::policy::Durability&
DataReaderQosImpl::policy<dds::core::policy::Durability>() const {
    return durability_;
}

template<>
::dds::core::policy::Durability&
DataReaderQosImpl::policy<dds::core::policy::Durability>() {
    return durability_;
}


template<>
const ::dds::core::policy::UserData&
DataReaderQosImpl::policy<dds::core::policy::UserData>() const {
    return user_data_;
}

template<>
::dds::core::policy::UserData&
DataReaderQosImpl::policy<dds::core::policy::UserData>() {
    return user_data_;
}


#ifdef  OMG_DDS_PERSISTENCE_SUPPORT

template<> const dds::core::policy::DurabilityService&
DataReaderQosImpl::policy<dds::core::policy::DurabilityService>() const {
    return durability_service_;
}

template<>
dds::core::policy::DurabilityService&
DataReaderQosImpl::policy<dds::core::policy::DurabilityService>() {
    return durability_service_;
}

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


template<> const dds::core::policy::Deadline&
DataReaderQosImpl::policy<dds::core::policy::Deadline>() const {
    return deadline_;
}

template<>
dds::core::policy::Deadline&
DataReaderQosImpl::policy<dds::core::policy::Deadline>() {
    return deadline_;
}


template<> const dds::core::policy::LatencyBudget&
DataReaderQosImpl::policy<dds::core::policy::LatencyBudget>() const {
    return budget_;
}

template<>
dds::core::policy::LatencyBudget&
DataReaderQosImpl::policy<dds::core::policy::LatencyBudget>() {
    return budget_;
}


template<> const dds::core::policy::Liveliness&
DataReaderQosImpl::policy<dds::core::policy::Liveliness>() const {
    return liveliness_;
}

template<>
dds::core::policy::Liveliness&
DataReaderQosImpl::policy<dds::core::policy::Liveliness>() {
    return liveliness_;
}


template<> const dds::core::policy::Reliability&
DataReaderQosImpl::policy<dds::core::policy::Reliability>() const {
    return reliability_;
}

template<>
dds::core::policy::Reliability&
DataReaderQosImpl::policy<dds::core::policy::Reliability>() {
    return reliability_;
}


template<> const dds::core::policy::DestinationOrder&
DataReaderQosImpl::policy<dds::core::policy::DestinationOrder>() const {
    return order_;
}

template<>
dds::core::policy::DestinationOrder&
DataReaderQosImpl::policy<dds::core::policy::DestinationOrder>() {
    return order_;
}


template<> const dds::core::policy::History&
DataReaderQosImpl::policy<dds::core::policy::History>() const {
    return history_;
}

template<>
dds::core::policy::History&
DataReaderQosImpl::policy<dds::core::policy::History>() {
    return history_;
}


template<> const dds::core::policy::ResourceLimits&
DataReaderQosImpl::policy<dds::core::policy::ResourceLimits>() const {
    return resources_;
}

template<>
dds::core::policy::ResourceLimits&
DataReaderQosImpl::policy<dds::core::policy::ResourceLimits>() {
    return resources_;
}


template<> const dds::core::policy::TransportPriority&
DataReaderQosImpl::policy<dds::core::policy::TransportPriority>() const {
    return priority_;
}

template<>
dds::core::policy::TransportPriority&
DataReaderQosImpl::policy<dds::core::policy::TransportPriority>() {
    return priority_;
}


template<> const dds::core::policy::Lifespan&
DataReaderQosImpl::policy<dds::core::policy::Lifespan>() const {
    return lifespan_;
}

template<>
dds::core::policy::Lifespan&
DataReaderQosImpl::policy<dds::core::policy::Lifespan>() {
    return lifespan_;
}


template<> const  dds::core::policy::Ownership&
DataReaderQosImpl::policy<dds::core::policy::Ownership>() const {
    return ownership_;
}

template<>
dds::core::policy::Ownership&
DataReaderQosImpl::policy<dds::core::policy::Ownership>() {
    return ownership_;
}


template<> const  dds::core::policy::TimeBasedFilter&
DataReaderQosImpl::policy<dds::core::policy::TimeBasedFilter>() const {
    return tfilter_;
}

template<>
dds::core::policy::TimeBasedFilter&
DataReaderQosImpl::policy<dds::core::policy::TimeBasedFilter>() {
    return tfilter_;
}


template<> const  dds::core::policy::ReaderDataLifecycle&
DataReaderQosImpl::policy<dds::core::policy::ReaderDataLifecycle>() const {
    return lifecycle_;
}

template<>
dds::core::policy::ReaderDataLifecycle&
DataReaderQosImpl::policy<dds::core::policy::ReaderDataLifecycle>() {
    return lifecycle_;
}

}}
