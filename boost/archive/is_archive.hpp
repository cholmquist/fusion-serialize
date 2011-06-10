/*=============================================================================
    Copyright (c) 2011 Christian Holmquist

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_ARCHIVE_IS_ARCHIVE_HPP
#define BOOST_ARCHIVE_IS_ARCHIVE_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/has_xxx.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost{
namespace archive
{

namespace detail
{
	BOOST_MPL_HAS_XXX_TRAIT_DEF(is_saving)
	BOOST_MPL_HAS_XXX_TRAIT_DEF(is_loading)
}

template<typename T, typename Enable = void>
struct is_iarchive : ::boost::mpl::false_
{
};

template<typename T>
struct is_iarchive<T, typename ::boost::enable_if<detail::has_is_loading<T> >::type>
	: T::is_loading
{
};

template<typename T, typename Enable = void>
struct is_oarchive : ::boost::mpl::false_
{
};

template<typename T>
struct is_oarchive<T, typename ::boost::enable_if<detail::has_is_saving<T> >::type>
	: T::is_saving
{
};

}} // namespace boost::archive

#endif
