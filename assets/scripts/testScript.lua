-- Test script
function init()
    math.randomseed(os.time())
    math.random(0, 800)
    math.random(0, 800)
    math.random(0, 800)
    math.random(0, 800)

    print("inited!")
end

count = 0

moving = false
targetX = 0
targetY = 0

function update(gameObj)
    --gameObj.transform.position.x = gameObj.transform.position.x + math.sin(count)
    --gameObj.transform.position.y = gameObj.transform.position.y + math.sin(count)

    gameObj.transform.scale.x = 0.03--math.abs(math.cos(count) * 2)
    gameObj.transform.scale.y = 0.03--math.abs(math.sin(count) * 2)
    --gameObj.transform.angle = math.abs(math.sin(count) * 360)
    --[[if not moving == true then
        targetX = math.random(0, 800)
        targetY = math.random(0, 600)
        moving = true
        print(targetX)
        print(targetY)
    --else]]
    targetX = Graphics.mouseX
    targetY = Graphics.mouseY
    if math.abs(targetX - gameObj.transform.position.x) < 10 and math.abs(targetY -gameObj.transform.position.y) < 10 then
        moving = false
    else
        gameObj.transform.position.x = gameObj.transform.position.x + ((targetX - gameObj.transform.position.x) / 1000)
        gameObj.transform.position.y = gameObj.transform.position.y + ((targetY - gameObj.transform.position.y) / 1000)
        gameObj.transform.angle = 90 + (((math.atan(((targetY - gameObj.transform.position.y)) / (targetX - gameObj.transform.position.x))) * (180 / 3.14)))
    end
    --end
    

    count = count + 0.001
end