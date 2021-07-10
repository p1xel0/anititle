#include <iostream>
#include <anitomy/anitomy.h>
#include <string>
#include <cstring>
#include <locale>
#include <codecvt>


std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
std::wstring s2ws(const std::string& str) {
	return converter.from_bytes(str);
}

void printHelp() {
	std::cout <<
		"anititle: Get the title of an anime using anitomy\n"
		"Usage:\n"
		"\tanititle [Input String] : outputs title of input"	<< std::endl;
}

int main(int argc, char** argv) {
	std::wstring input, title, year, output;
	if (argc == 2) {
		input = std::wstring(s2ws(argv[1]));
	} 
	else {
		printHelp();
		return 1;
	}
  
	anitomy::Anitomy anitomy;
	anitomy.Parse(input);
	auto& elements = anitomy.elements();
	
	year = elements.get(anitomy::kElementAnimeYear);
	title = elements.get(anitomy::kElementAnimeTitle);
	if(year.empty()) {
		output = title;
	}
	else {
		output = title + std::wstring(s2ws(" (")) + year + std::wstring(s2ws(")"));
	}
	std::wcout << output << std::endl;
  
	return 0;
}
