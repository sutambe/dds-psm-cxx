#ifndef IDDS_SUB_GENERATION_COUNT_IMPL_HPP_
#define IDDS_SUB_GENERATION_COUNT_IMPL_HPP_

namespace idds { namespace sub {
    class GenerationCount {
    public:
        inline int32_t disposed() const {
            return 0;
        }
        
        inline int32_t no_writers() const {
            return 0;
        }
    };
        
} }
#endif /* IDDS_SUB_GENERATION_COUNT_IMPL_HPP_ */

