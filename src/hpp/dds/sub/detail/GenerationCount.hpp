#ifndef OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_

#include <dds/sub/TGenerationCount.hpp>
#include <idds/sub/GenerationCountImpl.hpp>
namespace dds { namespace sub { namespace detail {
    typedef dds::sub::TGenerationCount< idds::sub::GenerationCount > GenerationCount;
} } }

#endif /* OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_ */
