#include <dds/sub/test/testSub.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/sub/sub.hpp>
#include <iostream>

using namespace dds::domain;
using namespace dds::sub;
using namespace dds::topic;

struct Point {
    uint32_t x;
    uint32_t y;
};


namespace dds { namespace topic {
    template<> struct is_topic_type<Point> {
        enum { value = 1 };
    };

    template<> struct topic_type_name<Point> {
        static std::string value() { return "Point"; }
    };
} }


int
dds::sub::test::testSub() {
    DomainParticipant dp(DomainId::default_domain());
    Topic<Point> topic(dp, "PointTopic");
    Subscriber sub(dp);

    DataReader<Point> dr(sub, topic);

    return 0;
}
