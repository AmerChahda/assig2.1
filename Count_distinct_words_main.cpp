
#include <iostream>
#include <list>
#include <iterator>
#include <sstream>

void printing_list(std::list<std::string>l_w,int dis_words_counter)
{
	std::cout<<"The total number of the distinct words are: "<<dis_words_counter<<"\nThees words are: ";
	for(auto i=std::begin(l_w);i!=std::end(l_w);++i)
	{
		std::cout<<*i<<"\t\n";
	}
}
void chech_the_rebetition_words(std::list <std::string>&l_w, std::list<std::string>&finel_list,int &counter)
{
	std::string temp;
	bool eq=false;
	while(!l_w.empty())
	{
		temp=l_w.front();
		l_w.pop_front();
		if (finel_list.empty())
		{
			finel_list.push_back(temp);
			counter++;
		}
		else
		{
			for(auto i=std::begin(finel_list);i!=std::end(finel_list);++i)
			{

				if (*i==temp)
				{
					eq=true;
					break;
				}
			}
			if(!eq)
			{
				finel_list.push_back(temp);
				counter++;
			}
			eq=false;
		}
	}
	printing_list(finel_list,counter);
}
int main()
{
	int counter=0;
		std::string value;
		std::string input_stream;
		std::list<std::string>word;
		std::list<std::string>dis_list;

		std::cout << "Please, insert your sentence: "<<std::endl;

		if (std::getline(std::cin,input_stream))
		{
			std::istringstream iss(input_stream);
			std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(word));

		}
		chech_the_rebetition_words(word,dis_list,counter);

	return 0;
}


