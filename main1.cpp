#include<SFML/Graphics.hpp>
#include<SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include<iostream>

//calculate the result
void calculateTheResult(std::string &result, sf::String &myInput) {
	std::string firstNum;
	std::string operation;
	std::string secondNum;
	if (myInput[0] == '-') {
		firstNum += myInput[0];
		for (sf::Int32 i = 1; i < myInput.getSize(); i++) {
			if (operation.empty() && (myInput[i] == '+' || myInput[i] == '-' || myInput[i] == '*' || myInput[i] == '/')) operation += myInput[i];
			else if (!operation.empty()) secondNum += myInput[i];
			else firstNum += myInput[i];
		}
		float first = std::stof(firstNum);
		float second = std::stof(secondNum);
		if (operation == "+") result = std::to_string(first + second);
		if (operation == "-") result = std::to_string(first - second);
		if (operation == "*") result = std::to_string(first * second);
		if (operation == "/") result = std::to_string(first / second);
	}
	else {
		for (sf::Int32 i = 0; i < myInput.getSize(); i++) {
			if (operation.empty() && (myInput[i] == '+' || myInput[i] == '-' || myInput[i] == '*' || myInput[i] == '/')) operation += myInput[i];
			else if (!operation.empty()) secondNum += myInput[i];
			else firstNum += myInput[i];
		}
		float first = std::stof(firstNum);
		float second = std::stof(secondNum);
		if (operation == "+") result = std::to_string(first + second);
		if (operation == "-") result = std::to_string(first - second);
		if (operation == "*") result = std::to_string(first * second);
		if (operation == "/") result = std::to_string(first / second);
	}
	myInput.clear();
}

//adding a backspace

void deleteTheLastChar(sf::String &myInput) {
	if (!myInput.isEmpty()) myInput.erase(myInput.getSize() - 1, 1);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(400, 400), "the most scientific calculator", sf::Style::Close | sf::Style::Titlebar);

	//adding more colors
	sf::Color darkGrey(93, 93, 93, 255);
	sf::Color orange(195, 85, 23, 255);

	//adding a font
	sf::Font font;
	font.loadFromFile("./Monument.ttf");
	
	//setting up input text
	sf::String myInput;
	std::string result;
	sf::Text myText;
	myText.setPosition(30, 10);
	myText.setFont(font);
	myText.setCharacterSize(80);
	myText.setFillColor(sf::Color::White);

	/*result text
	std::string result;
	sf::Text resultText;
	resultText.setPosition(30, 10);
	resultText.setFont(font);
	resultText.setCharacterSize(80);
	resultText.setFillColor(sf::Color::White);
	*/

	//rectangles for buttons
	sf::RectangleShape acButton;
	acButton.setSize(sf::Vector2f(80, 40));
	acButton.setFillColor(orange);
	acButton.setPosition(10, 110);

	sf::RectangleShape Button7;
	Button7.setSize(sf::Vector2f(80, 40));
	Button7.setFillColor(darkGrey);
	Button7.setPosition(10, 170);

	sf::RectangleShape Button4;
	Button4.setSize(sf::Vector2f(80, 40));
	Button4.setFillColor(darkGrey);
	Button4.setPosition(10, 230);

	sf::RectangleShape Button1;
	Button1.setSize(sf::Vector2f(80, 40));
	Button1.setFillColor(darkGrey);
	Button1.setPosition(10, 290);

	sf::RectangleShape Button0;
	Button0.setSize(sf::Vector2f(180, 40));
	Button0.setFillColor(darkGrey);
	Button0.setPosition(10, 350);

	sf::RectangleShape divideButton;
	divideButton.setSize(sf::Vector2f(80, 40));
	divideButton.setFillColor(darkGrey);
	divideButton.setPosition(110, 110);

	sf::RectangleShape Button8;
	Button8.setSize(sf::Vector2f(80, 40));
	Button8.setFillColor(darkGrey);
	Button8.setPosition(110, 170);

	sf::RectangleShape Button5;
	Button5.setSize(sf::Vector2f(80, 40));
	Button5.setFillColor(darkGrey);
	Button5.setPosition(110, 230);

	sf::RectangleShape Button2;
	Button2.setSize(sf::Vector2f(80, 40));
	Button2.setFillColor(darkGrey);
	Button2.setPosition(110, 290);

	sf::RectangleShape multiplyButton;
	multiplyButton.setSize(sf::Vector2f(80, 40));
	multiplyButton.setFillColor(darkGrey);
	multiplyButton.setPosition(210, 110);

	sf::RectangleShape Button9;
	Button9.setSize(sf::Vector2f(80, 40));
	Button9.setFillColor(darkGrey);
	Button9.setPosition(210, 170);

	sf::RectangleShape Button6;
	Button6.setSize(sf::Vector2f(80, 40));
	Button6.setFillColor(darkGrey);
	Button6.setPosition(210, 230);

	sf::RectangleShape Button3;
	Button3.setSize(sf::Vector2f(80, 40));
	Button3.setFillColor(darkGrey);
	Button3.setPosition(210, 290);

	sf::RectangleShape pointButton;
	pointButton.setSize(sf::Vector2f(80, 40));
	pointButton.setFillColor(darkGrey);
	pointButton.setPosition(210, 350);

	sf::RectangleShape minusButton;
	minusButton.setSize(sf::Vector2f(80, 40));
	minusButton.setFillColor(darkGrey);
	minusButton.setPosition(310, 110);

	sf::RectangleShape plusButton;
	plusButton.setSize(sf::Vector2f(80, 100));
	plusButton.setFillColor(darkGrey);
	plusButton.setPosition(310, 170);

	sf::RectangleShape equalButton;
	equalButton.setSize(sf::Vector2f(80, 100));
	equalButton.setFillColor(darkGrey);
	equalButton.setPosition(310, 290);

	//adding button names
	sf::Text ac("AC", font, 30);
	ac.setPosition(35, 110);

	sf::Text divide("/", font, 30);
	divide.setPosition(145, 110);

	sf::Text multiply("*", font, 80);
	multiply.setPosition(240, 100);

	sf::Text minus("-", font, 30);
	minus.setPosition(345, 110);

	sf::Text plus("+", font, 80);
	plus.setPosition(340, 170);

	sf::Text equal("=", font, 80);
	equal.setPosition(340, 290);

	sf::Text point(".", font, 80);
	point.setPosition(240, 295);

	sf::Text zero("0", font, 30);
	zero.setPosition(90, 350);

	sf::Text one("1", font, 30);
	one.setPosition(40, 290);

	sf::Text two("2", font, 30);
	two.setPosition(140, 290);

	sf::Text three("3", font, 30);
	three.setPosition(240, 290);

	sf::Text four("4", font, 30);
	four.setPosition(40, 230);

	sf::Text five("5", font, 30);
	five.setPosition(140, 230);

	sf::Text six("6", font, 30);
	six.setPosition(240, 230);

	sf::Text seven("7", font, 30);
	seven.setPosition(40, 170);

	sf::Text eight("8", font, 30);
	eight.setPosition(140, 170);

	sf::Text nine("9", font, 30);
	nine.setPosition(240, 170);


	while (window.isOpen()) {
		sf::Event event;
		

		while (window.pollEvent(event)) {
			//close the window
			if (event.type == event.Closed) {
				window.close();
			}
			//read input from keyboard
			if (event.type == sf::Event::TextEntered && ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 42 || event.text.unicode == 43 || event.text.unicode == 45 || event.text.unicode == 46 || event.text.unicode == 47)) {
				myInput += event.text.unicode;
				myText.setString(myInput);
			}
			if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Equal)) {
				calculateTheResult(result, myInput);
				myText.setString(result);
			}

			//delete the last character
			if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Backspace)) {
				deleteTheLastChar(myInput);
				myText.setString(myInput);
			}

			//read input using mouse
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				if (mousePosition.x >= 10 && mousePosition.x <= 90 && mousePosition.y >= 290 && mousePosition.y <= 330) myInput += "1";
				if (mousePosition.x >= 110 && mousePosition.x <= 190 && mousePosition.y >= 290 && mousePosition.y <= 330) myInput += "2";
				if (mousePosition.x >= 210 && mousePosition.x <= 290 && mousePosition.y >= 290 && mousePosition.y <= 330) myInput += "3";
				if (mousePosition.x >= 10 && mousePosition.x <= 90 && mousePosition.y >= 230 && mousePosition.y <= 270) myInput += "4";
				if (mousePosition.x >= 110 && mousePosition.x <= 190 && mousePosition.y >= 230 && mousePosition.y <= 270) myInput += "5";
				if (mousePosition.x >= 210 && mousePosition.x <= 290 && mousePosition.y >= 230 && mousePosition.y <= 270) myInput += "6";
				if (mousePosition.x >= 10 && mousePosition.x <= 90 && mousePosition.y >= 170 && mousePosition.y <= 210) myInput += "7";
				if (mousePosition.x >= 110 && mousePosition.x <= 190 && mousePosition.y >= 170 && mousePosition.y <= 210) myInput += "8";
				if (mousePosition.x >= 210 && mousePosition.x <= 290 && mousePosition.y >= 170 && mousePosition.y <= 210) myInput += "9";
				if (mousePosition.x >= 10 && mousePosition.x <= 190 && mousePosition.y >= 350 && mousePosition.y <= 390) myInput += "0";
				if (mousePosition.x >= 210 && mousePosition.x <= 290 && mousePosition.y >= 350 && mousePosition.y <= 390) myInput += ".";
				if (mousePosition.x >= 310 && mousePosition.x <= 390 && mousePosition.y >= 170 && mousePosition.y <= 270) myInput += "+";
				if (mousePosition.x >= 310 && mousePosition.x <= 390 && mousePosition.y >= 110 && mousePosition.y <= 150) myInput += "-";
				if (mousePosition.x >= 210 && mousePosition.x <= 290 && mousePosition.y >= 110 && mousePosition.y <= 150) myInput += "*";
				if (mousePosition.x >= 110 && mousePosition.x <= 190 && mousePosition.y >= 110 && mousePosition.y <= 150) myInput += "/";
				if (mousePosition.x >= 10 && mousePosition.x <= 90 && mousePosition.y >= 110 && mousePosition.y <= 150) myInput.clear();
				myText.setString(myInput);
				if (mousePosition.x >= 310 && mousePosition.x <= 390 && mousePosition.y >= 290 && mousePosition.y <= 390) {
					calculateTheResult(result, myInput);
					myText.setString(result);
				}
			}
		}



		window.clear();
		window.draw(myText);
		window.draw(acButton);
		window.draw(Button7);
		window.draw(Button4);
		window.draw(Button1);
		window.draw(Button0);
		window.draw(divideButton);
		window.draw(Button8);
		window.draw(Button5);
		window.draw(Button2);
		window.draw(multiplyButton);
		window.draw(Button9);
		window.draw(Button6);
		window.draw(Button3);
		window.draw(pointButton);
		window.draw(minusButton);
		window.draw(plusButton);
		window.draw(equalButton);
		window.draw(ac);
		window.draw(divide);
		window.draw(multiply);
		window.draw(minus);
		window.draw(plus);
		window.draw(equal);
		window.draw(point);
		window.draw(zero);
		window.draw(one);
		window.draw(two);
		window.draw(three);
		window.draw(four);
		window.draw(five);
		window.draw(six);
		window.draw(seven);
		window.draw(eight);
		window.draw(nine);
		window.display();
		
	}
	return 0;
}