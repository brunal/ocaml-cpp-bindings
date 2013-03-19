

class Rectangle {
public:
	int x, y, longueur, hauteur;

	Rectangle(int x,int y,int longueur,int hauteur);
	~Rectangle();

	void print();
	int perimetre();
	int surface();
};
