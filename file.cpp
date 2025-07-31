#include<iostream>
#include<fstream>

using namespace std;
class Encryptor {
    public:
        void encrypt(ifstream& infile, ofstream& outfile) {
           char ch;
           while(infile.get(ch)) {
            if(isalpha(ch)){
                char base;
                base = isupper(ch) ? 'A' : 'a';
                ch = (ch - base + 1) % 26 + base;
            }
            char decryptChar = ch + 1;
            outfile.put(decryptChar);
           }
        }
        void decrypt(ifstream& infile, ofstream& outfile) {
            char ch;
            while(infile.get(ch)) {
                if(isalpha(ch)){
                    char base;
                    base = isupper(ch) ? 'A' : 'a';
                    ch = (ch - base - 1 + 26) % 26 + base;
                }      
                char decryptedChar = ch - 1;
                
                outfile.put(decryptedChar);
            }
        }
        void encryptFile(const string& inputFile, const string& outputFile) {
            ifstream infile(inputFile);
            if (!infile) {
                throw "Error opening input file.";
                return;}
            ofstream outfile(outputFile);
            if (!outfile) {
                 throw "Error opening output file.";
                return;
            }
            encrypt(infile, outfile);
            infile.close();
            outfile.close();
        }
        void decryptFile(const string& inputFile, const string& outputFile) {
            ifstream infile(inputFile);
            if (!infile) {
                throw runtime_error("Error opening input file.");
                return;
            }
            ofstream outfile(outputFile);
            if (!outfile) {
                throw runtime_error("Error opening output file.");
                return; 
            }
            decrypt(infile, outfile);
            infile.close();
            outfile.close();
        }
    };
    
    
                                                                       
    
int main(){
    string inputfile;
    cout << "Enter the input file name: ";
    cin >> inputfile;
    string outputfile;
    cout << "Enter the output file name: ";
    cin >> outputfile;
    ifstream infile(inputfile);
    if (!infile) {
        throw "Error opening input file.";
        return 1;
    }
    ofstream outfile(outputfile);
    if (!outfile) {
        throw "Error opening output file.";
        return 1;
    }
    // encrypt the file and write to output file using class
    //Encryptor encryptor;
   // encryptor.encryptFile(inputfile, outputfile);
  try{ 
     Encryptor decryptor;
    decryptor.decryptFile(inputfile, outputfile);
    outfile.close();
    infile.close();

}    
    catch(const char* e) {
        cout << "An error occurred: " << e << endl;
    }
    catch (...) {
        cout << "An unknown error occurred." << endl;
    }

    return 0;
}