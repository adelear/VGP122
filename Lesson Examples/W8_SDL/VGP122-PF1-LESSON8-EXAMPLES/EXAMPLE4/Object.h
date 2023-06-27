#pragma once

class Object
{
public:
	virtual ~Object() = default;
	
	virtual void update() = 0;
	virtual void render() = 0;
};