#include <iostream>
#include <vector>
using namespace std;


class Music{
public:
	virtual void song() = 0;
};



class Rock : public Music{
public:
	virtual void song(){
		cout << "!! ROCK IT HARD !!" << endl;
	}
};

class Country : public Music{
public:
	virtual void song(){
		cout << "!! COUNTRY ROAD TAKE ME HOME !!" << endl;
	}
};

class MusicFactory{
public:
	//Factory Method
	Music* make_Music(char type){
		Music *music = NULL;

		switch (type)
		{
		case 'R':
			music = new Rock();
			break;
		case 'C':
			music = new Country();
			break;
		default:
			break;
		}
		return music;

	}

};


int main()
{
	MusicFactory *musicFactory = new MusicFactory();

	cout << "!!WHAT TYPE OF MUSIC YOU WANT :- [R] for ROCK and [C] for COUNTRY!!" << endl;

	char type;
	cin >> type;

	Music *music = musicFactory->make_Music(type);

	cout << "Music: ";
	if (music)
	{
		music->song();
	}
	else
		cout << "Wrong Selection" << endl;
	system("pause");
}

