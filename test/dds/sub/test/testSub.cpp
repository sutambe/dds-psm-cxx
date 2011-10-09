#include <dds/sub/test/testSub.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/sub/Subscriber.hpp>

using namespace dds::domain;
using namespace dds::sub;

int
dds::sub::test::testSub() {
    DomainParticipant dp(DomainId::default_domain());
    Subscriber sub(dp);
    
    return 0;
}