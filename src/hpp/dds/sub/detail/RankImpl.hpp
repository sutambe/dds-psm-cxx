#ifndef OMG_IDDS_SUB_RANK_IMPL_HPP_
#define OMG_IDDS_SUB_RANK_IMPL_HPP_

namespace idds { namespace sub {
    
class RankImpl {
public:
    inline int32_t absolute_generation() const {
        return 0;
    }
    
    inline int32_t generation() const {
        return 0;
    }
    
    inline int32_t sample() const {
        return 0;
    }
};

} }  
#endif /* OMG_IDDS_SUB_RANK_IMPL_HPP_ */