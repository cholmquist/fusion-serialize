/*=============================================================================
    Copyright (c) 2011 Christian Holmquist

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/sequence/io.hpp>
#include <boost/fusion/sequence/comparison/equal_to.hpp>
#include <boost/fusion/sequence/serialization.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/container/generation/make_list.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <sstream>

namespace archive = boost::archive;
namespace fusion = boost::fusion;

template<class T>
void roundtrip(const T& a)
{
	std::stringstream s;
	T b = T();
	{
		archive::text_oarchive oa(s);
		oa << a;
	}
	{
		archive::text_iarchive ia(s);
		ia >> b;
	}
	BOOST_TEST_EQ(a, b);
}

int main()
{
	roundtrip(42); // Sanity check
	roundtrip(fusion::vector<>());
	roundtrip(fusion::make_vector(1, 2.0f, std::string("Franz Kafka")));
	roundtrip(fusion::make_list(1, 2.0f, std::string("Franz Kafka")));
	return boost::report_errors();
}
