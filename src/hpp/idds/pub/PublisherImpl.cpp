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


//#include <dds/pub/Publisher.hpp>
// Include DomainParticipantHolder so that auto_ptr can see its destructor:
//#include <dds/core/ref_traits.hpp>

#include <idds/pub/PublisherImpl.hpp>
#include <dds/domain/DomainParticipant.hpp>

namespace idds { namespace pub {

    PublisherImpl::PublisherImpl(const dds::domain::DomainParticipant& dp,
                                 const dds::pub::qos::PublisherQos& qos,
                                 dds::pub::PublisherListener* listener,
                                 const dds::core::status::StatusMask& event_mask) 
    :   dp_(dp),
        qos_(qos),
        listener_(listener),
        mask_(event_mask),
        default_dwqos_() { }

/*
    template <typename T>
    std::vector<dds::pub::DataWriter<T> >
    lookup_datawriter(const std::string& topic_name);
*/


const dds::pub::qos::PublisherQos
PublisherImpl::qos() const { return qos_; }

bool
PublisherImpl::wait_for_acknowledgments(const dds::core::Duration& max_wait) {
    return true;
}
    /*

const dds::domain::detail::DomainParticipantHolder*
PublisherImpl::parent() const {
    return dp_.get();
}
*/
bool
PublisherImpl::suspend_publications() {
    return true;
}

bool
PublisherImpl::resume_publications() {
    return true;
}

void
PublisherImpl::begin_coherent_changes() { }

void
PublisherImpl::end_coherent_changes() { }

void
PublisherImpl::close() { }

void
PublisherImpl::default_writer_qos(const dds::pub::qos::DataWriterQos& dwqos) {
    default_dwqos_ = dwqos;
}

const dds::pub::qos::DataWriterQos
PublisherImpl::default_writer_qos() const {
     return default_dwqos_;
}

}}
