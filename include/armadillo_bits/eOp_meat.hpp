// Copyright (C) 2010-2011 NICTA (www.nicta.com.au)
// Copyright (C) 2010-2011 Conrad Sanderson
// 
// This file is part of the Armadillo C++ library.
// It is provided without any warranty of fitness
// for any purpose. You can redistribute this file
// and/or modify it under the terms of the GNU
// Lesser General Public License (LGPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


//! \addtogroup eOp
//! @{



template<typename T1, typename eop_type>
eOp<T1, eop_type>::eOp(const Base<typename T1::elem_type, T1>& in_m)
  : P(in_m.get_ref())
  {
  arma_extra_debug_sigprint();
  }



template<typename T1, typename eop_type>
eOp<T1, eop_type>::eOp(const Base<typename T1::elem_type, T1>& in_m, const typename T1::elem_type in_aux)
  : P(in_m.get_ref())
  , aux(in_aux)
  {
  arma_extra_debug_sigprint();
  }



template<typename T1, typename eop_type>
eOp<T1, eop_type>::eOp(const Base<typename T1::elem_type, T1>& in_m, const uword in_aux_uword_a, const uword in_aux_uword_b)
  : P(in_m.get_ref())
  , aux_uword_a(in_aux_uword_a)
  , aux_uword_b(in_aux_uword_b)
  {
  arma_extra_debug_sigprint();
  }



template<typename T1, typename eop_type>
eOp<T1, eop_type>::eOp(const Base<typename T1::elem_type, T1>& in_m, const typename T1::elem_type in_aux, const uword in_aux_uword_a, const uword in_aux_uword_b)
  : P(in_m.get_ref())
  , aux(in_aux)
  , aux_uword_a(in_aux_uword_a)
  , aux_uword_b(in_aux_uword_b)
  {
  arma_extra_debug_sigprint();
  }



template<typename T1, typename eop_type>
eOp<T1, eop_type>::~eOp()
  {
  arma_extra_debug_sigprint();
  }

  

template<typename T1, typename eop_type>
arma_inline
uword
eOp<T1, eop_type>::get_n_rows() const
  {
  return P.get_n_rows();
  }
  


template<typename T1, typename eop_type>
arma_inline
uword
eOp<T1, eop_type>::get_n_cols() const
  {
  return P.get_n_cols();
  }



template<typename T1, typename eop_type>
arma_inline
uword
eOp<T1, eop_type>::get_n_elem() const
  {
  return P.get_n_elem();
  }



template<typename T1, typename eop_type>
arma_inline
typename T1::elem_type
eOp<T1, eop_type>::operator[] (const uword i) const
  {
  return eop_core<eop_type>::process(P[i], aux);
  }



template<typename T1, typename eop_type>
arma_inline
typename T1::elem_type
eOp<T1, eop_type>::at(const uword row, const uword col) const
  {
  return eop_core<eop_type>::process(P.at(row, col), aux);
  }



//! @}
