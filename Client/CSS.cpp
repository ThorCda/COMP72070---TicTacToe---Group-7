#include <QWidget>
#include <QPushButton>
#include "CSS.h"



void setButtonCSS(QPushButton* button)
{
	QString css = "QPushButton { align-items: center;"
		"background-color: #0A66C2;"
		"border: 0;"
		"box-sizing: border-box;"
		"color: #ffffff;"
		"cursor: pointer;"
		"display: inline-flex;"
		"font-family: system-ui;"
		"font-size: 16px;"
		"font-weight: 600;"
		"justify-content: center;"
		"line-height: 20px;"
		"max-width: 125px;"
		//"min-width: 125px;"
		"min-height: 40px;"
		"overflow: hidden;"
		"padding: 0px;"
		"padding-left: 20px;"
		"padding-right: 20px;"
		"text-align: center;"
		"vertical-align: middle;"
		"}"
		"QPushButton:hover,"
		"QPushButton:focus {"
		"background-color: #16437E;"
		"color: #ffffff;"
		"}";
		/*"QPushButton:active {"
		"background: #09223b;"
		"color: rgb(255,255,255,.7);"
		"}"
		"QPushButton:disabled {"
		"cursor: not-allowed;"
		"background: rgba(0,0,0,.08);"
		"color: rgba(0,0,0,.3);"
		"}";*/

	button->setStyleSheet(css);
	return;
}