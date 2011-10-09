#ifndef OMG_DDS_DOMAIN_DOMAIN_ID_IMPL_HPP_
#define OMG_DDS_DOMAIN_DOMAIN_ID_IMPL_HPP_

namespace idds { namespace domain {

    class DomainIdImpl {
    public:
        DomainIdImpl(uint32_t id) : id_(id) { }
        
        DomainIdImpl(uint32_t id, std::string name) 
        : id_(id), name_(name) { }
        
        uint32_t value() const { 
            return id_;
        }
        
        std::string name() { return name_; }
        
        static  uint32_t default_domain() {
            return 0;
        }
        
    private:
        uint32_t id_;
        std::string name_;
    };
    
} }

#endif /* OMG_DDS_DOMAIN_DOMAIN_ID_IMPL_HPP_ */