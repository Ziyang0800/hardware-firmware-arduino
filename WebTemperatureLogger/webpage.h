#ifndef _WEBPAGE_H
	#define _WEBPAGE_H

const PROGMEM char Page1[] = {
"<html>"
"<head>"
"  <title>SVG Graphs example</title>"

"  <style type='text/css'>"
"  body {"
"    background-color: #b2e9e4;"
"  }"

"  svg.graph {"
"    height: 500px;"
"    width: 800px;"
"  }"

"  svg.graph .grid {"
"    stroke: white;"
"    stroke-dasharray: 1 2;"
"    stroke-width: 1;"
"  }"

"  svg.graph .points {"
"    stroke: white;"
"    stroke-width: 3;"
"  }"
"  svg.graph .first_set {"
"    fill: #00554d;"
"  }"

"  svg.graph .surfaces {"
"    fill-opacity: 0.5;"
"  }"

"  svg.graph .grid.double {"
"    stroke-opacity: 0.4;"
"  }"

"  svg.graph .labels {"
"    font-family: Arial;"
"    font-size: 14px;"
"    kerning: 1;"
"  }"

"  svg.graph .labels.x-labels {"
"    text-anchor: middle;"
"  }"

"  svg.graph .labels.y-labels {"
"    text-anchor: end;"
"  }"
"  </style>"

"</head>"

"<body>"
"  <svg class='graph' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink' xmlns='http://www.w3.org/2000/svg'>"
"    <g class='grid x-grid' id='xGrid'>"
"      <line x1='113' x2='113' y1='10' y2='380'></line>"
"      <line x1='259' x2='259' y1='10' y2='380'></line>"
"      <line x1='405' x2='405' y1='10' y2='380'></line>"
"      <line x1='551' x2='551' y1='10' y2='380'></line>"
"      <line x1='697' x2='697' y1='10' y2='380'></line>"
"    </g>"
"    <g class='grid y-grid' id='yGrid'>"
"      <line x1='86' x2='697' y1='10' y2='10'></line>"
"      <line x1='86' x2='697' y1='68' y2='68'></line>"
"      <line x1='86' x2='697' y1='126' y2='126'></line>"
"      <line x1='86' x2='697' y1='185' y2='185'></line>"
"      <line x1='86' x2='697' y1='243' y2='243'></line>"
"      <line x1='86' x2='697' y1='301' y2='301'></line>"
"      <line x1='86' x2='697' y1='360' y2='360'></line>"
"    </g>"


"    <g class='surfaces'>"
"        <path class='first_set' d='M113,360 L113,192 L259,171 L405,179 L551,200 L697,204 L697,360 Z'></path>"
"    </g>"

"    <use class='grid double' xlink:href='#xGrid' style=''></use>"
"    <use class='grid double' xlink:href='#yGrid' style=''></use>"

"    <g class='first_set points' data-setname='Our first data set'>"
"      <circle cx='113' cy='192' data-value='7.2' r='5'></circle>"
"      <circle cx='259' cy='171' data-value='8.1' r='5'></circle>"
"      <circle cx='405' cy='179' data-value='7.7' r='5'></circle>"
"      <circle cx='551' cy='200' data-value='6.8' r='5'></circle>"
"      <circle cx='697' cy='204' data-value='6.7' r='5'></circle>"
"    </g>"


"    <g class='labels x-labels'>"
"        <text x='113' y='400'>2008</text>"
"        <text x='259' y='400'>2009</text>"
"        <text x='405' y='400'>2010</text>"
"        <text x='551' y='400'>2011</text>"
"        <text x='697' y='400'>2012</text>"
"    </g>"
"    <g class='labels y-labels'>"
"        <text x='80' y='15'>15</text>"
"        <text x='80' y='131'>10</text>"
"        <text x='80' y='248'>5</text>"
"        <text x='80' y='365'>0</text>"
"        <text x='50' y='15'>Weeks</text>"
"    </g>"
"  </svg>"
"</body>"
"</html>"
"%END"
};
#endif //_WEBPAGE_H,0x00
