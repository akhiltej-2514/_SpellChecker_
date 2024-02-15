#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>
#include "algorithmspellcheck.h"

unordered_map<string, int> dictwords;

using namespace std;

int main(int argc, const char * argv[]) {
    Spellcheck_name_space::SpellChecker obj;
    ifstream inputFile("en-80k.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string word;
    uint64_t frequency;
    int line = 0;
    cout<<"Loading dictionary........"<<endl;
    cout<<"usually take 10 sec........"<<endl;
    cout<<"Hang tight........"<<endl;
    while (inputFile >> word >> frequency) {
        line++;
        dictwords[word]++;
      obj.Entry_Dictonary(word.c_str(),frequency);
    }
    cout<<"Total words in dictionary are: "<<line<<endl;

    inputFile.close();

    cout<<"Dictionary loaded successfully"<<endl;
 
    vector<string> words;
    word="";
    ifstream file("misspelled_words.txt");
    while (file >> word)
    {
        words.push_back(word);
    }
    file.close();
    cout<<"Total words in input.txt file are: "<<words.size()<<endl;

    int np=0;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < words.size(); i++)
    {
        vector< std::unique_ptr<Spellcheck_name_space::SuggestItem>> items;
        if(dictwords.find(words[i])!=dictwords.end())
        {
            cout<<words[i]<<" is correct word"<<endl;
            continue;
        }

        obj.Find_best_suggestion(words[i].c_str(), Spellcheck_name_space::Filter_::Best_Match, items);
        cout << "Suggestions for " << words[i] << " are: ";
        if(items.size()==0)
        {
           np++;
        }
        for (auto& item : items) {
            cout << item->term << " ";
        }
        cout << endl;
    }
    //end timer
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // total time taken by program
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    cout<<"Accuracy of spell checker is: "<<(float)(words.size()-np)/words.size()*100<<"%"<<endl;
 return 0;
}