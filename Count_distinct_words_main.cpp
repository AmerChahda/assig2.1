/*
 * Count_distinct_words_main.cpp
 *
 *  Created on: 4 juli 2018
 *      Author: ACH11739
 */
/*#include <iostream>
#include <string>
#include <vector>
#include <iterator>

int main() {
	std::vector<std::string>p_vector;
	std::string word;
	std::cout<<"Enter your sentence to check how many words: "<<std::endl;
	std::istream_iterator<std::string>eos;              // end-of-stream iterator
	std::istream_iterator<std::string>iit(std::cin);
	//std::getline(std::cin,word);


	while(iit!=eos){
		p_vector.push_back(*iit);
		++iit;
	}
	for(std::vector<std::string>::iterator i=p_vector.begin();i!=p_vector.end();++i)
		std::cout<<*i<<"\n";
	return 0;
}
*/

// istream_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator
#include <vector>

int main () {
	int counter;
	std::string value;
	std::vector<std::string>w;
  std::cout << "Please, insert two values: "<<std::endl;

  std::istream_iterator<std::string> eos;              // end-of-stream iterator
  std::istream_iterator<std::string> iit (std::cin);   // stdin iterator

  w.push_back(*iit);
  ++iit;
  ++counter;
  while(iit!=eos)
  {
	  value=*iit;
	 for (int i=0;i<=w.size();++i)
	 {
		 if(value!=w[i])
		 {
			 w.push_back(value);
		 }
	 }
	 ++iit;
  }



  std::cout << value << "  " << value << "\n";

  return 0;
}

