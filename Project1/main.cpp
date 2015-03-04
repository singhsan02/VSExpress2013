#include <iostream>
#include <vector>
using namespace std;

/*
class Music{
public:
	virtual void song() = 0;
};
*/

class MusicFactory{
public:
	//Factory method
	static MusicFactory *make_Music(int type);
	virtual void song() = 0;

};

class Rock : public MusicFactory{
public:
	virtual void song(){
		cout << "!! ROCK IT HARD !!" << endl;
	}
};

class Country : public MusicFactory{
public:
	virtual void song(){
		cout << "!! COUNTRY ROAD TAKE ME HOME !!" << endl;
	}
};




int main()
{
	vector <MusicFactory*> vMusic;
	int type;

	while (1)
	{
		cout << "Enter (1 for ROCK) (2 for COUNTRY)(0 to Exit) ";
		cin >> type;
			if (type == 0)
				break;
			vMusic.push_back(MusicFactory::make_Music(type));
			
    }
		
	for (int i = 0; i < vMusic.size(); ++i){
		vMusic[i]->song();
	}
	

	
	system("pause");
}


MusicFactory *MusicFactory::make_Music(int type){
		 if (type == 1)
		{
			return new Rock;
		}
		else if (type == 2)
		{
			return new Country;
		}
}