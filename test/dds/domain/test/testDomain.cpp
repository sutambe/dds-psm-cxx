#include <dds/domain/DomainParticipant.hpp>
#include "testDomain.hpp"

using namespace dds::domain;

int dds::domain::test::testDomain() {
    DomainId did = 0;
    DomainParticipant dp(did);
    DomainParticipant dp2 = dds::core::null;
    dp2 = DomainParticipant(dds::domain::DomainId(2));
    DomainParticipant dp3(DomainId::default_domain());
    qos::DomainParticipantQos dpqos;
    DomainParticipant dp4(DomainId::default_domain(), dpqos);
    return 0;
}
