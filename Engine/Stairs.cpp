#include "Stairs.h"

Stairs::Stairs( const Vec2& pos )
	:
	pos( pos ),
	hitbox( pos,float( size.x ),float( size.y ) )
{
	Despawn();
}

void Stairs::Draw( Graphics& gfx ) const
{
	if( activated )
	{
		gfx.DrawRect( int( pos.x ),int( pos.y ),
			size.x,size.y,Colors::Cyan );

		// gfx.DrawHitbox( hitbox );
	}
}

void Stairs::Spawn( const Vec2& whereTo )
{
	pos = whereTo;
	hitbox.MoveTo( whereTo );
	activated = true;
}

void Stairs::Despawn()
{
	activated = false;
	pos = { -50.0f,-50.0f };
}

const Rect& Stairs::GetRect() const
{
	return( hitbox );
}