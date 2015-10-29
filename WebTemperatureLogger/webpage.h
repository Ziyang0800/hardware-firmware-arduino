#ifndef _WEBPAGE_H
	#define _WEBPAGE_H

const PROGMEM char Page1[] = {

"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n"
"<html>\n"
"<head>\n"
"<title>Temperature</title>\n"
"<script>\n"
"const G_TOP = 25;\n"
"const G_LEFT = 50;\n"
"const G_WIDTH = 20 * 25;\n"
"const G_HEIGHT = 13 * 25;\n"

"const G_MARGIN_PY = 25;\n"
"const G_MARGIN_PX = 25;\n"
"const G_GRID_PY = 25;\n"
"const G_GRID_PX = 25;\n"
"const G_ZERO_PY = G_TOP + G_MARGIN_PY + 10 * G_GRID_PY;\n"


"var data = [];\n"
"var svgNS = \"http://www.w3.org/2000/svg\";\n"

"function Init()\n"
"{\n"
"DrawChart();\n"
"IntervalComboInit();\n"
"GetTemperature();\n"
"}\n"

"function DrawChart()\n"
"{\n"
"DrawGrid();\n"
"InitPath();\n"
"}\n"

"function InitPath()\n"
"{\n"
"for(var i = 0; i < 20; i++) {\n"
"data[i] = 0;\n"
"} \n"

"var gPath = document.createElementNS(svgNS,\"g\");\n"
"gPath.setAttributeNS(null, \"class\",\"surfaces\");\n"

"var path = document.createElementNS(svgNS,\"path\");\n"
"path.setAttributeNS(null,\"id\",\"path\");\n"
"path.setAttributeNS(null,\"class\",\"first_set\");\n"

"var pathAttrib = \"M\" + (G_LEFT + G_MARGIN_PX) + \", \" + G_ZERO_PY;\n"
"for(var i = 0; i < 21; i++) {\n"
"pathAttrib += \" L0, 0\"\n"
"}        \n"
"pathAttrib += \" Z\";\n"

"path.setAttributeNS(null,\"d\", pathAttrib);\n"
"gPath.appendChild(path);\n"

"// circles\n"
"var gCircles = document.createElementNS(svgNS,\"g\");\n"
"gCircles.setAttributeNS(null, \"class\",\"first_set points\");\n"
"gCircles.setAttributeNS(null, \"data-setname\", \"Our first data set\");\n"

"var x = 45;\n"
"for(var i = 0; i < 20; i++) {\n"
"var circle = document.createElementNS(svgNS,\"circle\")\n"
"circle.setAttributeNS(null,\"id\",\"c\" + i);\n"
"circle.setAttributeNS(null,\"cx\",x);\n"
"circle.setAttributeNS(null,\"cy\",75);\n"
"circle.setAttributeNS(null,\"r\",5);\n"
"circle.setAttributeNS(null,\"visibility\",\"hidden\");\n"
"gCircles.appendChild(circle);\n"
"x += G_GRID_PX;\n"
"}\n"

"document.getElementById(\"temp-graph\").appendChild(gPath);\n"
"document.getElementById(\"temp-graph\").appendChild(gCircles);\n"
"}\n"

"function DrawGrid()\n"
"{\n"
"var gGrid = document.createElementNS(svgNS,\"g\");\n"
"gGrid.setAttributeNS(null, \"class\",\"grid x-grid\");\n"
"gGrid.setAttributeNS(null, \"id\", \"xGrid\");\n"

"// draw vertical lines\n"
"var x = G_LEFT + G_MARGIN_PX;\n"
"for(var i = 0; i < 20; i++) {\n"
"var line = document.createElementNS(svgNS,\"line\");\n"
"line.setAttributeNS(null,\"x1\",x);\n"
"line.setAttributeNS(null,\"x2\",x);\n"
"line.setAttributeNS(null,\"y1\",G_TOP + G_MARGIN_PY);\n"
"line.setAttributeNS(null,\"y2\",G_TOP + G_HEIGHT + G_MARGIN_PY);\n"
"gGrid.appendChild(line);\n"
"x += G_GRID_PX;\n"
"}\n"

"// draw horizontal lines\n"
"var y = G_TOP + G_MARGIN_PY;\n"
"for(var i = 0; i < 14; i++) {            \n"
"var line = document.createElementNS(svgNS,\"line\");\n"
"line.setAttributeNS(null,\"x1\", G_LEFT + G_MARGIN_PX);\n"
"line.setAttributeNS(null,\"x2\", G_LEFT + G_WIDTH);\n"
"line.setAttributeNS(null,\"y1\", y);\n"
"line.setAttributeNS(null,\"y2\", y);\n"
"gGrid.appendChild(line);\n"
"y += G_GRID_PY;\n"
"}\n"

"// draw x axis\n"
"var xAxis = document.createElementNS(svgNS,\"g\");\n"
"xAxis.setAttributeNS(null, \"class\",\"labels x-labels\");\n"
"xAxis.setAttributeNS(null, \"id\", \"xAxisLabels\");\n"

"x = G_LEFT + G_MARGIN_PX;\n"
"for(var i = 1; i < 21; i++) {\n"
"var text = document.createElementNS(svgNS,\"text\");\n"
"text.setAttributeNS(null,\"x\", x);\n"
"text.setAttributeNS(null,\"y\", G_TOP + G_HEIGHT + 2 * G_MARGIN_PY);\n"
"text.textContent = i;\n"
"xAxis.appendChild(text);\n"
"x += G_GRID_PX;\n"
"}\n"

"// draw y axis\n"
"var yAxis = document.createElementNS(svgNS,\"g\");\n"
"yAxis.setAttributeNS(null, \"class\",\"labels y-labels\");\n"
"yAxis.setAttributeNS(null, \"id\", \"yAxisLabels\");\n"

"y = G_TOP + G_MARGIN_PY + 5;\n"
"for(var i = 100; i > -40; i -= 10) {\n"
"var text = document.createElementNS(svgNS,\"text\");\n"
"text.setAttributeNS(null,\"x\", G_LEFT);\n"
"text.setAttributeNS(null,\"y\", y);\n"
"text.textContent = i;\n"
"yAxis.appendChild(text);\n"
"y += G_GRID_PY;\n"
"}\n"

"var text = document.createElementNS(svgNS,\"text\");\n"
"text.setAttributeNS(null,\"x\", G_LEFT);\n"
"text.setAttributeNS(null,\"y\", G_TOP);\n"
"text.textContent = \"°C\";\n"
"yAxis.appendChild(text);\n"

"document.getElementById(\"temp-graph\").appendChild(gGrid);\n"
"document.getElementById(\"temp-graph\").appendChild(xAxis);\n"
"document.getElementById(\"temp-graph\").appendChild(yAxis);\n"
"}\n"

"function GetTemperature()\n"
"{\n"
"var request = new XMLHttpRequest();\n"

"request.onreadystatechange = function()\n"
"{\n"
"if (this.readyState == 4) {\n"
"if (this.status == 200) {\n"
"if (this.responseXML != null) {\n"
"for(var i = 0; i < 20; i++) {\n"
"data[i] = this.responseXML.getElementsByTagName('analog')[i].childNodes[0].nodeValue;\n"
"}\n"
"UpdateGraph();\n"
"}\n"
"}\n"
"}\n"
"}\n"

"request.open(\"GET\", \"temperatur_data\", true);\n"
"request.send(null);\n"

"setTimeout(\"GetTemperature()\", 3000);\n"
"}\n"

"function UpdateGraph()\n"
"{\n"
"var path = document.getElementById(\"path\");\n"
"var segments = path.pathSegList;\n"

"var x = G_LEFT + G_MARGIN_PX;\n"

"segments.getItem(0).y = G_ZERO_PY;\n"
"segments.getItem(0).x = x;\n"

"segments.getItem(21).y = G_ZERO_PY;\n"
"segments.getItem(21).x = G_LEFT + G_WIDTH;\n"

"for(var i = 0; i < 20; i++) {\n"
"var y = data[i] * -2.5 + G_ZERO_PY;\n"
"var circle = document.getElementById(\"c\" + i);\n"
"circle.setAttributeNS(null, \"cy\", y);\n"
"circle.setAttributeNS(null, \"cx\", x);\n"
"if(data[i] != G_ZERO_PY)\n"
"circle.setAttributeNS(null,\"visibility\",\"visible\");\n"

"segments.getItem(i+1).y = parseInt(y);\n"
"segments.getItem(i+1).x = x;\n"

"x += G_GRID_PX;\n"
"}\n"

"for(var i = 0; i < 21; i++) {\n"
"data[i] = data[i + 1];\n"
"}\n"
"}\n"


"functionOnStartLog()\n"
"{\n"
"var request = new XMLHttpRequest();\n"
"request.open(\"GET\", \"start_log\", true);\n"
"request.send(null);\n"
"}\n"

"function OnStoppLog()\n"
"{\n"
"var request = new XMLHttpRequest();\n"
"request.open(\"GET\", \"stopp_log\", true);\n"
"request.send(null);\n"
"}\n"

"function IntervalComboInit()\n"
"{\n"
"var intervalInputBox = document.getElementById(\"intervalInput\");\n"
"var intervalComboBox = document.getElementById(\"intervalCombo\");\n"
"var idx = intervalComboBox.selectedIndex;\n"
"var content = intervalComboBox.options[idx].value;\n"
"if(intervalInputBox.value == \"\")\n"
"intervalInputBox.value = content;\n"
"}\n"

"function IntervalComboOnChange(intervalComboBox, intervalInputBox)\n"
"{\n"
"intervalInputBox = document.getElementById(intervalInputBox);  \n"
"var idx = intervalComboBox.selectedIndex;\n"
"var content = intervalComboBox.options[idx].value;\n"
"intervalInputBox.value = content;\n"
"}\n"
"</script>\n"
"<style type=\"text/css\">\n"
"body {\n"
"background-color: #b8b8b8;\n"
"}\n"
"svg.graph {    \n"
"height: 400px;\n"
"width: 600px;\n"
"}\n"
"svg.graph .grid {\n"
"stroke: white;\n"
"stroke-dasharray: 1 2;\n"
"stroke-width: 1;\n"
"}\n"
"svg.graph .points {\n"
"stroke: white;\n"
"stroke-width: 3;\n"
"}\n"
"svg.graph .first_set {\n"
"fill: #000000;\n"
"}\n"
"svg.graph .surfaces {\n"
"fill-opacity: 0.5;\n"
"}\n"
"svg.graph .grid.double {\n"
"stroke-opacity: 0.4;\n"
"}\n"
"svg.graph .labels {\n"
"font-family: Arial;\n"
"font-size: 14px;\n"
"kerning: 1;\n"
"}\n"
"svg.graph .labels.x-labels {\n"
"text-anchor: middle;\n"
"}\n"
"svg.graph .labels.y-labels {\n"
"text-anchor: end;       \n"
"}\n"
"fieldset {\n"
"padding-top:10px;\n"
"padding-bottom:10px;\n"
"font-family: Arial;\n"
"font-size: 12px;\n"
"kerning: 1;\n"
"width: 600px;\n"
"border:1px solid #666;\n"
"border-radius:4px;    \n"
"}   \n"
"</style>\n"
"</head>\n"
"<body onload=\"Init()\">\n"
"<fieldset name=\"graph\">\n"
"<legend>Temperature</legend>\n"
"<svg id = 'temp-graph' class='graph' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink' xmlns='http://www.w3.org/2000/svg'>\n"
"</fieldset>\n"
"<form method = \"get\" action=\"file.txt\">\n"
"<p/>\n"
"<fieldset name=\"logging\">\n"
"<legend>Logging</legend>\n"
"<table style=\"width:100%\">\n"
"<tr>\n"
"<td>\n"
"<input name=\"START_LOG\" value=\"Start Log\" type=\"button\" onclick=\"OnStartLog()\">\n"
"<input name=\"STOPP_LOG\" value=\"Stopp Log\" type=\"button\" onclick=\"OnStoppLog()\">\n"
"</td>\n"
"<td>\n"
"<label>Interval[s]:</label>\n"
"<input type=\"text\" id=\"intervalInput\" name=\"intervalInput\" style=\"width: 50px\"/>\n"
"<select id=\"intervalCombo\" name=\"intervalCombo\" onChange=\"IntervalComboOnChange(this, \"intervalInput\")\">\n"
"<option value=\"1\">1s</option>\n"
"<option value=\"60\">1m</option>\n"
"<option value=\"600\">10m</option>\n"
"<option value=\"3600\">1h</option>\n"
"</select>    \n"
"</td> \n"
"<td>\n"
"<label>State:</label>\n"
"<label id = \"stateLabel\"><font color=\"red\"><b>Off</b></font></label>\n"
"</td>\n"
"</tr> \n"
"</table>\n"
"</fieldset>\n"
"<p/>\n"
"<fieldset name=\"files\">\n"
"<legend>Files</legend>\n"
"<select name=\"download\" size=\"5\" style=\"width: 300px\">\n"
"<option>0000.csv</option>\n"
"</select>\n"
"<p/>\n"
"<input name=\"refreshButton\" value=\"Refresh\" type=\"submit\">\n"
"<input name=\"downloadButton\" value=\"Download\" type=\"submit\">\n"
"</fieldset>\n"
"</body>\n"
"</html>\n"
""
"%END"
};

const PROGMEM char Page2[] = {
"1000\r\n"
"2000\r\n"
"%END"
};

#endif //_WEBPAGE_H
