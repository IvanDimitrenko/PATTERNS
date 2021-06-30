#include<iostream>
#include<list>
#include<vector>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::endl;



class Gazillion
{
public:
	Gazillion(int value_one)
	{
		m_value_one = value_one;
		cout << "ctor: " << m_value_one << '\n';
	}
	~Gazillion()
	{
		cout << m_value_one << ' ';
	}
	void report(int value_two)
	{
		cout << m_value_one << value_two << ' ';
	}
private:
	int m_value_one;
};


class Factory
{
public:
	static Gazillion *get_fly(int in)
	{
		if (!s_pool[in])
			s_pool[in] = new Gazillion(in);
		return s_pool[in];
	}
	static void clean_up()
	{
		cout << "dtors: ";
		for (int i = 0; i < X; ++i)
			if (s_pool[i])
				delete s_pool[i];
		cout << '\n';
	}
	static int X, Y;
private:
	static Gazillion *s_pool[];
};

int Factory::X = 6, Factory::Y = 10;
Gazillion *Factory::s_pool[] =
{
  0, 0, 0, 0, 0, 0
};



class Icon
{
public:
	Icon(const char *fileName)
	{
		strcpy_s(_name, fileName);
		if (!strcmp(fileName, "go"))
		{
			_width = 20;
			_height = 20;
		}
		if (!strcmp(fileName, "stop"))
		{
			_width = 40;
			_height = 40;
		}
		if (!strcmp(fileName, "select"))
		{
			_width = 60;
			_height = 60;
		}
		if (!strcmp(fileName, "undo"))
		{
			_width = 30;
			_height = 30;
		}
		
	}
	~Icon()
	{
		//cout << "D" << endl;
	}
	const char *getName()
	{
		return _name;
	}
	void draw(int x, int y)
	{
		cout << "   drawing " << _name << ": upper left (" << x << "," << y <<
			") - lower right (" << x + _width << "," << y + _height << ")" <<
			endl;
	}
	Icon() { _width = NULL, _height = NULL; };
private:
	char _name[20];
	int _width;
	int _height;
};

class FlyweightFactory
{
public:
	static Icon *getIcon(const char *name)
	{
		for (int i = 0; i < _numIcons; i++)
		{
			if (!strcmp(name, _icons[i]->getName())) // if name == icon.name return exists icon
			{
				return _icons[i];
			}
		}

		_icons[_numIcons] = new Icon(name);			// else create new 
		return _icons[_numIcons++];
	}
	static void reportTheIcons()
	{
		cout << "Active Flyweights: ";
		for (int i = 0; i < _numIcons; i++)
			cout << _icons[i]->getName() << " ";
		cout << endl;
	}

private:
	enum
	{
		MAX_ICONS = 5
	};
	static int _numIcons;
	static Icon *_icons[MAX_ICONS];
};

int FlyweightFactory::_numIcons = 0;
Icon *FlyweightFactory::_icons[];

class DialogBox
{
public:
	DialogBox(int x, int y, int incr) : _iconsOriginX(x), _iconsOriginY(y),
		_iconsXIncrement(incr) {}
	virtual void draw() = 0;
protected:
	Icon *_icons[3];
	int _iconsOriginX;
	int _iconsOriginY;
	int _iconsXIncrement;
};

class FileSelection : public DialogBox
{
public:
	FileSelection(Icon *first, Icon *second, Icon *third) : DialogBox(100, 100,
		100)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	}
	void draw()
	{
		cout << "drawing FileSelection:" << endl;
		for (int i = 0; i < 3; i++)
			_icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
	}
};

class CommitTransaction : public DialogBox
{
public:
	CommitTransaction(Icon *first, Icon *second, Icon *third) : DialogBox(150,
		150, 150)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	}
	void draw()
	{
		cout << "drawing CommitTransaction:" << endl;
		for (int i = 0; i < 3; i++)
			_icons[i]->draw(_iconsOriginX + (i *_iconsXIncrement), _iconsOriginY);
	}
};

class A
{
public:
	~A()
	{
		cout << "D\t" << this << endl;
	}
	A() {};
};


int main(int argc, char **argv)
{



	int n = 100000;
	Icon** arr = new Icon*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new Icon();
	}
	cout << "END" << endl;
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	
	Icon** brr = new Icon*[n];
	for (int i = 0; i < n; i++)
	{
		brr[i] = FlyweightFactory::getIcon("a");
	}
	cout << "END" << endl;

	


	/*DialogBox *dialogs[3];
	dialogs[0] = new FileSelection(FlyweightFactory::getIcon("go"),
		FlyweightFactory::getIcon("stop"), FlyweightFactory::getIcon("select"));
	dialogs[1] = new CommitTransaction(FlyweightFactory::getIcon("select"),
		FlyweightFactory::getIcon("stop"), FlyweightFactory::getIcon("undo"));
	dialogs[2] = new CommitTransaction(FlyweightFactory::getIcon("select"),
		FlyweightFactory::getIcon("stop"), FlyweightFactory::getIcon("a"));

	for (int i = 0; i < std::size(dialogs); i++)
		dialogs[i]->draw();
*/
	//FlyweightFactory::reportTheIcons();
	
	/*
	for (int i = 0; i < Factory::X; ++i)
	{
		for (int j = 0; j < Factory::Y; ++j)
			Factory::get_fly(i)->report(j);
		cout << '\n';
	}
	Factory::clean_up();
	*/

	return 0;
}