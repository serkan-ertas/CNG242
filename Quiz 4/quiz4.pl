%%%*** Serkan Ertas ***%%%

% ***1***
function(X, R):-number(X), X > 3, R is X*X*X*X*X + 4*X + 1.
function(X, R):-number(X), X < 0, R is X*X*X + 5*X*X + 2.
function(X, R):-number(X), X >= 0, X =< 3, R is X*X*X*X*X.


% ***2***
geo(A, 1, _, X):-X is A.
geo(A, Order, Ratio, X):-Order > 1, Order2 is Order - 1, geo(A, Order2, Ratio, X1),
						 X is X1 * Ratio.


% ***3***
% RACE
% id, name, leader, region, weapon
race(1, 'Hobit', 'Bilbo Baggins', 'Shire', 'Knife').
race(2, 'Dwarf', 'Thrain II', 'Iron Hills', 'Hammer').
race(3, 'Elf', 'Elrond Peredhel', 'Rivendell', 'Bow').

% Character
% id, name, surname, age
character(3, 'Legolas', 'Greenleaf', 2931).
character(2, 'Thorin', 'Oakenshield', 195).
character(1, 'Samwise', 'Gamgee', 38).
character(2, 'Dain', 'Ironfoot', 32).

% *** A ***
leader_of_Shire(Leader):-race(_, _, Leader, 'Shire', _).

% *** B ***
elders_town(Age, Region):-character(Id, _, _, Age), race(Id, _, _, Region, _), Age>1000.

% *** C ***
hammerman_young(Race, Name, Surname):-race(Id, Race, _, _, 'Hammer'), character(Id, Name, Surname, Age), Age<100.