#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>


int isNum;
std::string fileName;
std::filebuf file;
std::string  islem="DOSYA EKLEME : 1,DOSYA OKUMA:2,DOSYA S�LME:3,DOSYA ARAMA:4, c�k�s:5";

static void readFile()
{
	std::cout << "l�tfen dosya ad�n� giriniz";
	std::cin >> fileName;
	file.open(fileName, std::ios_base::in);
	if (file.is_open())
	{
		std::istream fileStream(&file);
		std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());

		std::cout << "dosya i�eri�i\n" << content;
		file.close();

	}

	else
	{
		std::cout << "dosya acilmadi";
	}




}

static void addFile()
{
	
	std::string fileName;
	bool isValid = false;

	while (!isValid) {
		std::cout << "Eklemek istediginiz dosya ad�n� ve uzantisini giriniz: ";
		std::cin >> fileName;

		if (fileName.empty()) {
			std::cout << "Dosya ad� bo� olamaz. L�tfen tekrar deneyin.\n";
			continue; 
		}

	
		std::ofstream file(fileName);

		if (file.is_open()) {
			std::cout << "Dosya ba�ar�l� bir �ekilde olu�turuldu.\n";
			std::string text;
			std::cout << "Eklemek istedi�iniz metni giriniz: ";
			std::cin.ignore();  
			std::getline(std::cin, text);

			file << text; 
			file.close();  
			std::cout << "Metin ba�ar�yla dosyaya eklendi." << std::endl;
			isValid = true;  
		}
		else {
			std::cout << "HATA! Dosya olu�turulamad�. L�tfen dosya ad�n� ve yolunu kontrol edin.\n";
		}
	}
		
		
	

  }


static void removeFile()
{

	std::cout << "silmek istediginiz dosya adini giriniz:";
	std::cin >> fileName;

	
	if (std::filesystem::remove(fileName)) {
		std::cout << "Dosya silindi: " << fileName << std::endl;
	}
	else {
		std::cout << "Dosya silinemedi!" << std::endl;
	}



	

}


static void searchFile()
{
	std::string directoryPath;
	std::cout << "Arama yapmak istediginiz klas�r�n yolunu giriniz: ";
	std::cin >> directoryPath;

	if (!std::filesystem::exists(directoryPath))
	{
		std::cout << "Hata: Klas�r bulunamad�!" << std::endl;
		return;
	}

	for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
	{
		std::cout << "Bulunan dosya: " << entry.path().filename() << std::endl;
	}
	


}

static void fileManager()
{
	std::cout << "Dosya yoneticisi baslatildi\n";

	bool isContiune = true;

		while(isContiune)

		{

			std::cout << "yapmak istediginiz islemi seciniz:" << islem;
			std::cin >> isNum;
			switch (isNum)
			{
	         case 1:

				 addFile();
				break;

			case 2:
				readFile();
				
				break;

			case 3:
				
				removeFile();
				break;
			case 4:
				searchFile();
				
				break;

			case 5:
				isContiune = false;
				break;
			}
		};
}

int main()
{

	fileManager();

	
	return 0;
}