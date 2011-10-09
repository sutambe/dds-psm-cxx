#ifndef OMG_IDDS_CORE_FUNCTOR_HOLDER_HPP
#define OMG_IDDS_CORE_FUNCTOR_HOLDER_HPP

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



namespace idds { namespace core {

   class FunctorHolder {
   public:
      virtual ~FunctorHolder();
      virtual void invoke() = 0;
   };

   template <typename Functor>
   class VoidFunctorHolder : public FunctorHolder {
   public:
      VoidFunctorHolder(const Functor& func)
         : func_(func) { }

      virtual ~VoidFunctorHolder() { }

   public:
      virtual void invoke() {
         func_();
      }
   private:
      Functor func_;
   };

   template <typename Functor, typename ARG1>
   class OneArgFunctorHolder : public FunctorHolder {
   public:
      OneArgFunctorHolder(const Functor& func, const ARG1& arg1)
      : func_(func), arg1_(arg1) { }

      virtual ~OneArgFunctorHolder() { }

   public:
      virtual void invoke() {
         func_(arg1_);
      }
   private:
      Functor func_;
      ARG1 arg1_;
   };

   template <typename Functor, typename ARG1, typename ARG2>
   class TwoArgFunctorHolder : public FunctorHolder {
   public:
      TwoArgFunctorHolder(const Functor& func,
                          const ARG1& arg1,
                          const ARG2& arg2)
      :  func_(func),
         arg1_(arg1),
         arg2_(arg2)
      { }

      virtual ~TwoArgFunctorHolder() { }

   public:
      virtual void invoke() {
         func_(arg1_, arg2_);
      }
   private:
      Functor func_;
      ARG1 arg1_;
      ARG2 arg2_;
   };

} }

#endif /* OMG_IDDS_CORE_FUNCTOR_HOLDER_HPP */

