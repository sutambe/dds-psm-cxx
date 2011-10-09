#include <dds/topic/test/testTopic.hpp>

#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/topic/TopicTraits.hpp>

using namespace dds::domain;
using namespace dds::topic;
using namespace dds::core;

class Point {
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

int dds::topic::test::testTopic() {
    DomainParticipant dp(DomainId::default_domain());
    Topic<Point> topic(dp, "PointTopic");

    std::cout 
        << "Topic Name = " << topic.name() 
        << " Type Name = " << topic.type_name()
    << std::endl;    
    
    qos::TopicQos tqos;
    tqos << policy::Reliability::Reliable() 
         << policy::Durability::Transient()
         << policy::History::KeepLast(5);
    
    TopicListener<Point>* ptl = 0; 
    Topic<Point> topic2(dp, 
                        "PointTopic2", 
                        "Point2", 
                        tqos, 
                        ptl, 
                        status::StatusMask::offered_incompatible_qos()); 
    
    return 0;
}