#ifndef OMG_DDS_SUB_DETAIL_RANK_HPP
#define OMG_DDS_SUB_DETAIL_RANK_HPP

#include <dds/sub/TRank.hpp>
#include <idds/sub/RankImpl.hpp>

namespace dds { namespace sub { namespace detail {
    typedef dds::sub::TRank< ::idds::sub::RankImpl > Rank;
} } }

#endif /* OMG_DDS_SUB_DETAIL_RANK_HPP */