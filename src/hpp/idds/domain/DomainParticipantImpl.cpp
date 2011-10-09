/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
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

#include <dds/domain/DomainParticipant.hpp>

dds::domain::qos::DomainParticipantQos idds::domain::DomainParticipantImpl::DomainParticipantImpl::default_domain_qos_;

idds::domain::DomainParticipantImpl::DomainParticipantImpl(dds::domain::DomainId id)
{
    OMG_DDS_LOG("MM", "DomainParticipantImpl(id)");
}


idds::domain::DomainParticipantImpl::DomainParticipantImpl
    (dds::domain::DomainId id,
     const dds::domain::qos::DomainParticipantQos& qos,
     dds::domain::DomainParticipantListener* listener,
     const dds::core::status::StatusMask&) 
{
    OMG_DDS_LOG("MM", "DomainParticipantImpl(id, qos)");
}

idds::domain::DomainParticipantImpl::~DomainParticipantImpl() {
    OMG_DDS_LOG("MM", "~DomainParticipantImpl()");
}

/*
void idds::domain::DomainParticipantImpl::listener(
        dds::domain::DomainParticipantListener* the_listener,
        const dds::core::status::StatusMask& event_mask) {
}
 */

dds::domain::DomainParticipantListener*
idds::domain::DomainParticipantImpl::listener() const {
    return NULL;
}

dds::domain::DomainId
idds::domain::DomainParticipantImpl::domain_id() {
    return 0;
}

void
idds::domain::DomainParticipantImpl::assert_liveliness() { }

bool
idds::domain::DomainParticipantImpl::contains_entity(const dds::core::InstanceHandle& handle) {
    return false;
}

dds::core::Time
idds::domain::DomainParticipantImpl::current_time() {
    return dds::core::Time();
}

const dds::domain::qos::DomainParticipantQos
idds::domain::DomainParticipantImpl::qos() const {
	return this->qos_;
}


void
idds::domain::DomainParticipantImpl::qos(const dds::domain::qos::DomainParticipantQos& the_qos) {

}

void
idds::domain::DomainParticipantImpl::close() { }

const dds::topic::qos::TopicQos& 
idds::domain::DomainParticipantImpl::default_topic_qos() const {
    return default_topic_qos_;
}

void 
idds::domain::DomainParticipantImpl::default_topic_qos(const dds::topic::qos::TopicQos& qos) {
    default_topic_qos_ = qos;
}

const ::dds::pub::qos::PublisherQos&
idds::domain::DomainParticipantImpl::default_publisher_qos() const {
    return default_pub_qos_;
}

void 
idds::domain::DomainParticipantImpl::default_publisher_qos(const ::dds::pub::qos::PublisherQos& qos)
{
    default_pub_qos_ = qos;
}

const ::dds::sub::qos::SubscriberQos& 
idds::domain::DomainParticipantImpl::default_subscriber_qos() const {
    return default_sub_qos_;
}

void 
idds::domain::DomainParticipantImpl::default_subscriber_qos(const ::dds::sub::qos::SubscriberQos& qos)
{
    default_sub_qos_ = qos;
}

const ::dds::domain::qos::DomainParticipantQos& 
idds::domain::DomainParticipantImpl::default_domain_qos() {
    return default_domain_qos_;
}
void 
idds::domain::DomainParticipantImpl::default_domain_qos(const ::dds::domain::qos::DomainParticipantQos& qos) 
{
    default_domain_qos_ = qos;
}


/*
namespace idds { namespace domain {

template <>
dds::core::cond::StatusCondition<dds::domain::DomainParticipant>
DomainParticipantImpl::status_condition<dds::domain::DomainParticipant>(const dds::domain::DomainParticipant& self) const {
    return dds::core::cond::StatusCondition<dds::domain::DomainParticipant>(
        new dds::core::cond::detail::StatusCondition<dds::domain::DomainParticipant>(self));
}

} }
*/
