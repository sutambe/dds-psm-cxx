#include <iostream>

#include <dds/domain/test/testDomain.hpp>
#include <dds/pub/test/testPub.hpp>
#include <dds/sub/test/testSub.hpp>
#include <dds/topic/test/testTopic.hpp>

int main(int, char**) {
  std::cout << ">>>>>>>>>>>>>>>>>>> Testing Domain" << std::endl;
  dds::domain::test::testDomain();

  std::cout << "\n\n>>>>>>>>>>>>>>>>>>> Testing Publisher" << std::endl;
  dds::pub::test::testPub();

  std::cout << "\n\n>>>>>>>>>>>>>>>>>>> Testing Subscriber" << std::endl;
  dds::sub::test::testSub();

  std::cout << "\n\n>>>>>>>>>>>>>>>>>>> Testing Topic" << std::endl;
  dds::topic::test::testTopic();

  return 0;
}
