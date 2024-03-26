#include <iostream>
#include <string>

int main()
{
  std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  std::cout << "Enter your security message: ";
  std::string message{};
  std::getline(std::cin, message);

  std::cout << "Encrypting..." << std::endl;

  std::string encryptedMesage{};
  for (const char &letter : message)
  {
    int index = alphabet.find(letter);
    if (index == std::string::npos)
    {
      encryptedMesage += letter;
    }
    else
    {

      encryptedMesage += key.at(index);
    }
  }

  std::cout << "The encrypted message is: " << encryptedMesage << std::endl;

  std::cout << "Decrypting..." << std::endl;

  std::string decryptedMessage{};

  for (const char &letter : encryptedMesage)
  {
    int index = key.find(letter);
    if (index == std::string::npos)
    {
      decryptedMessage += letter;
    }
    else
    {
      decryptedMessage += alphabet.at(index);
    }
  }

  std::cout << "The decrypted message is:" << decryptedMessage << std::endl;

  return 0;
}
