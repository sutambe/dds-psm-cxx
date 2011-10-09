#ifndef OMG_DDS_CORE_STATUS_DETAIL_STATUS_HPP_
#define OMG_DDS_CORE_STATUS_DETAIL_STATUS_HPP_

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

#include <dds/core/status/TStatus.hpp>
#include <idds/core/StatusImpl.hpp>


namespace dds { namespace core { namespace status { namespace detail {
    typedef dds::core::status::TInconsistentTopicStatus< idds::core::InconsistentTopicStatusImpl >
    InconsistentTopicStatus;
    
    typedef dds::core::status::TLivelinessChangedStatus <idds::core::LivelinessChangedStatusImpl>
    LivelinessChangedStatus;
    
    typedef dds::core::status::TLivelinessLostStatus<idds::core::LivelinessLostStatusImpl>
    LivelinessLostStatus;
    
    typedef dds::core::status::TOfferedDeadlineMissedStatus<idds::core::OfferedDeadlineMissedStatusImpl>
    OfferedDeadlineMissedStatus;
    
    typedef dds::core::status::TOfferedIncompatibleQosStatus<idds::core::OfferedIncompatibleQosStatusImpl>
    OfferedIncompatibleQosStatus;
    
    typedef dds::core::status::TPublicationMatchedStatus<idds::core::PublicationMatchedStatusImpl>
    PublicationMatchedStatus;
    
    typedef dds::core::status::TSampleRejectedStatus< idds::core::SampleRejectedStatusImpl >
    SampleRejectedStatus;
    
    typedef dds::core::status::TRequestedDeadlineMissedStatus<idds::core::RequestedDeadlineMissedStatusImpl>
    RequestedDeadlineMissedStatus;
    
    typedef dds::core::status::TRequestedIncompatibleQosStatus<idds::core::RequestedIncompatibleQosStatusImpl>
    RequestedIncompatibleQosStatus;
    
    typedef dds::core::status::TSampleLostStatus<idds::core::SampleLostStatusImpl>
    SampleLostStatus;
    
    typedef dds::core::status::TSubscriptionMatchedStatus<idds::core::SubscriptionMatchedStatusImpl>
    SubscriptionMatchedStatus;
} } } } // namespace dds::core::status::detail


#endif /* OMG_DDS_CORE_STATUS_DETAIL_STATUS_HPP_ */
