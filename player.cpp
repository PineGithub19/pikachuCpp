struct Info {
	string name;
	int scores = 0;
}; 

void initPlayer(Info &player) {
	cout << "Enter Your Name: ";
	getline(cin, player.name);
}
