
cup flOz = \_ -> flOz
-- Basic constructor
cup flOz = \message ->  message flOz
getOz aCup = aCup (\flOz -> flOz)
drink aCup ozDrank = if ozDiff > 0 
                      then cup ozDiff
                      else cup 0
    where flOz = getOz aCup
          ozDiff = (flOz - ozDrank)

isEmpty aCup = getOz aCup  == 0

-- Fighting robot
robot (name, attack, hp) = \message -> message (name, attack, hp)
name (n, _, _) = n
attack (_, a, _) = a
hp (_, _, hp) = hp

getName aRobot = aRobot name
getAttack aRobot = aRobot attack
getHp aRobot = aRobot hp

setName aRobot newName = aRobot (\(n,a,h) -> robot (newName, a, h))
setAttack aRobot newAttack = aRobot (\(n,a,h) -> robot (n, newAttack, h))
setHp aRobot newHp = aRobot (\(n,a,h) -> robot (n, a, newHp))

printRobot aRobot = aRobot (\(n,a,h) -> n ++
                                      " attack: " ++ (show a) ++
                                      " hp: " ++ (show h))

damage aRobot attackDamage = aRobot (\(n,a,h) ->
                                      robot (n,a,h-attackDamage))

killerRobot = robot ("K1ll3r", 25, 200)
gentleGiant = robot ("Mr. Friendly", 10, 300)
afterHit = damage killerRobot 40

fight aRobot defender = damage defender attack
    where attack = if getHp aRobot > 10
                    then getAttack aRobot
                    else 0

gentleGiantRound1 = fight killerRobot gentleGiant
killerRobotRound1 = fight gentleGiant killerRobot
gentleGiantRound2 = fight killerRobotRound1 gentleGiantRound1
killerRobotRound2 = fight gentleGiantRound1 killerRobotRound1
gentleGiantRound3 = fight killerRobotRound2 gentleGiantRound2
killerRobotRound3 = fight gentleGiantRound2 killerRobotRound2

--new fight
fastRobot = robot ("speedy", 15, 40)
slowRobot = robot ("slowpoke",20,30)

fastRobotRound1 = fight slowRobot fastRobot
slowRobotRound1 = fight fastRobot slowRobot
fastRobotRound2 = fight slowRobotRound1 fastRobotRound1
slowRobotRound2 = fight fastRobotRound1 slowRobotRound1
fastRobotRound3 = fight slowRobotRound2 fastRobotRound2
slowRobotRound3 = fight fastRobotRound2 slowRobotRound2

-- 1.- Use map on a list of robots to get the life of each robot in the list
allRobots = [killerRobot, gentleGiant, fastRobot, slowRobot]
getAllRobotsHp robotList = map getHp robotList
-- 2.- Write a 'threeRoundFight' function that takes two robots and makes them fight for three rounds and returns the winner
threeRoundFight aRobot bRobot = 1

 
fightMany aRobot robotList = map (threeRoundFight aRobot) robotList
getRobotListHp robotList = map getHp robotList