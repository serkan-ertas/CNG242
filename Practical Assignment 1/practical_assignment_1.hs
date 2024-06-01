-- *** Serkan Ertas *** ---

data Unitree = Node [Char] Integer [Unitree] deriving (Show, Eq, Ord)

-- organisation tree constructor helper function
-- otherVal = number of children of other nodes between the actual parent and child
-- if childVal == 0, then func stops,
-- if otherVal != 0, then there are at least otherVal children between the actual parent and child
-- when adding a child to the [Unitree], function called for children
unitreeHelper (dataList) (actualList) (Node name employee childList) childVal otherVal =
            if childVal == 0
            then Node name employee childList
            else if otherVal /= 0
            then (unitreeHelper (tail dataList) (tail actualList) (Node name employee childList) childVal (otherVal - 1 + (head actualList)))
            else (unitreeHelper (tail dataList) (tail actualList) (Node name employee (childList ++ [(unitreeHelper (tail dataList) (tail actualList) (Node (fst (head dataList)) (snd (head dataList)) []) (head actualList) 0)])) (childVal - 1) (otherVal + (head actualList)))

unitree (tuple:dataList) (x:xs) = unitreeHelper dataList xs (Node (fst tuple) (snd tuple) []) x 0

-- ********* helpers for other functions ********* --
getChildVal (Node name employee childList) = length childList
getName (Node name employee childList) = name

-- a helper function that returns the total of employees
-- !!! THIS FUNC ADDS WITHOUT A CONDITION !!! ---
sectionsizeHelper (Node name employee []) childVal = employee
sectionsizeHelper (Node name employee childList) childVal =
            if childVal > 1 then employee + (sectionsizeHelper (Node name 0 (tail childList)) (childVal-1)) + (sectionsizeHelper (head childList) (getChildVal (head childList)))
            else employee + (sectionsizeHelper (head childList) (getChildVal (head childList)))

-- if it can find the Node named name2, it calls sectionsizeHelper
-- otherwise 0
sectionsize (Node name employee childList) name2 =
            if (name == name2)
            then sectionsizeHelper (Node name employee childList) (length childList)
            else if ((length childList) /= 0)
            then (sectionsize (Node name employee (tail childList)) name2) + (sectionsize (head childList) name2)
            else 0

-- if there is no child, then ""
-- if its first child Node's name is name2, then this Node is the "immediate section that is responsible"
-- else call the function with the first child and the rest
managingentity (Node name employee childList) name2 =
            if ((length childList) == 0)
            then ""
            else if ((getName (head childList)) == name2)
            then name
            else (managingentity (Node name employee (tail childList)) name2) ++ (managingentity (head childList) name2)

-- this function returns ancestorList if correct path, emptyList if wrong path
-- then adds all those lists, since empties does NOT affect ancestorList, returned object is ancestorList if exist
-- *** algorithm ***
-- if not node2 && leaf -> empty list
-- if not node2 && internal -> call func for all children -- [with currentNodeName] ++ ancestorList
-- if node2 -> ancestorList
managelistHelper (Node name employee []) name2 ancestorList =
            if name == name2
            then ancestorList
            else []
managelistHelper (Node name employee childList) name2 ancestorList =
            if name == name2
            then ancestorList
            else (managelistHelper (head childList) name2 (name:ancestorList)) ++ (managelistHelper (Node name employee (tail childList)) name2 (ancestorList))

managelist tree name = (managelistHelper tree name [])