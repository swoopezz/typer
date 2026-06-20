#include <fstream>
#include <random>
#include <stdexcept>
#include <vector>
#include <string>

class Dict {
private:
	std::vector<std::string> dict;

public:
	explicit Dict(const std::string& path) {
		std::ifstream file(path);
		if (file.fail())
			throw std::runtime_error("cannot open dict file: " 
					"" + path);
		
		std::string currentLine;
		while (std::getline(file, currentLine)) {
			dict.push_back(currentLine);
		}
		file.close();
	}

	const std::string& randomWord() const {	
		std::random_device rd;
		std::mt19937 engine(rd());
		std::uniform_int_distribution<int> dist(0, dict.size()-1);
		return dict[dist(engine)];
	}

	std::string generateSentence(Dict& dict, int len) {
		std::string words;

		for (int i = 0; i <= len; i++) {
			if (i == len) {
				words.append(dict.randomWord());
				continue;
			}
			std::string space = dict.randomWord() + " ";
			words.append(space);
		}

		return words;
}
};
