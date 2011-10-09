#ifndef OMG_DDS_SUB_T_LOANED_SAMPLES_HPP_
#define OMG_DDS_SUB_T_LOANED_SAMPLES_HPP_

#include <dds/sub/detail/LoanedSample.hpp>

namespace dds { namespace sub {
    template <typename T, 
              template <typename Q>  DELEGATE = detail::LoanedSamples>
    class LoanedSamples;    
} }

template <typename T, template <typename Q>  DELEGATE>
class dds::sub::LoanedSamples : public dds::core::Value< DELEGATE<T> >
{
public:
    typedef T DataType;
    typedef Sample<DataType> SampleType;
    
public:
    LoanedSamples() { }
    LoanedSamples(const LoanedSamples& src);
    
    /**
     * Implicitly return the loan. The specifics of how the loan is returned
     * are encapsulated in the implementation layer.
     */
    ~LoanedSamples() { }
    
public:
    class Iterator : public std::iterator<std::forward_iterator_tag, const SampleType>
    {
    public:
        Iterator() { /* implementation-defined */ }
        Iterator(const Iterator& src) { /* implementation-defined */ }
        ~Iterator() { /* implementation-defined */ }
        
    public:
        Iterator& operator=(const Iterator& src);
        
        bool operator==(const Iterator& other) const {
            // implementation-defined
            return false;
        }
        bool operator!=(const Iterator& other) const {
            // implementation-defined
            return false;
        }
        
        Iterator& operator++() {    // prefix
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::Iterator::++");
        }
        Iterator  operator++(int) { // postfix
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::Iterator::++");
        }
        
        const SampleType& operator*() {
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::begin");
        }
        const SampleType* operator->() {
            // implementation-defined
            throw dds::core::UnsupportedError("LoanedSamples::end");
        }
    };
    
public:
    const Iterator begin() const {
        // implementation-defined
        throw dds::core::UnsupportedError("LoanedSamples::begin");
    }
    
    const Iterator end() const {
        // implementation-defined
        throw dds::core::UnsupportedError("LoanedSamples::end");
    }
    
public:
    void return_loan();     // explicitly return loan
    
};

#endif /* OMG_DDS_SUB_T_LOANED_SAMPLES_HPP_ */