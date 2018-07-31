
#include <iostream>
#include <list>
#include <iterator>
#include <sstream>

void printing_list(std::list<std::string>l_w,int dis_words_counter)
{
	std::cout<<"The total number of the distinct words are: "<< dis_words_counter <<"\nThees words are: \n";
	for (std::list <std::string>::iterator i = std::begin(l_w);i != std::end(l_w); ++i)
	{
		std::cout << *i <<"\n";
	}
}


//-------This function to get the distinct words and how many are they-----------.
void check_the_rebetition_words (std::list <std::string> &l_w, std::list <std::string> &final_list,int &counter)
{
	std::string temp; // Temporary variable.
	bool eq = false; // Equality flag.

	while (!l_w.empty()) // Repeat the following instructions while there are words in the words list.
	{
		temp = l_w.front();
		l_w.pop_front(); //Remove the first element from the list.

		//Three status we must take care of:

		if (final_list.empty())	// 1- If the final_list "the distinct words list" is empty ==>> first element will add to it.
		{
			final_list.push_back(temp);
			counter++;
		}

		else
		{
			for (std::list <std::string>:: iterator i = std::begin(final_list); i != std::end(final_list); ++i)
			{

				// 2- The  list is not empty and the element already exist in.
				if (*i == temp)
				{
					eq = true;	// Change the equality flag to true ==>> element is exist.
					break;
				}
			}

			// 3- The  list is not empty and the element is not exist in.
			if (!eq)
			{
				final_list.push_back(temp);
				counter++;
			}

			eq = false;
		}
	}

	printing_list(final_list,counter);  // Call the printing function.
}

//-------------------------The Main Function------------------------

int main()
{
	int counter=0;
	std::string input_stream;
	std::list<std::string>word;
	std::list<std::string>dis_list;

	std::cout << "Please, insert your sentence: " << std::endl;

	if (std::getline(std::cin, input_stream))	// Get the string from user.
	{
		std::istringstream iss(input_stream);	// Get out the words from input sentence via ignore the white space.
		std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(word));	// Insert the words in the list.
	}

	check_the_rebetition_words(word, dis_list, counter); // Call the check_the_rebetition_words(&word, &dis_list, &counter) pass the original copy for list word, an empty list for the distinct words and counter.

	return 0;
}


