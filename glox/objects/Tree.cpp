#include "Tree.hpp"

using namespace std;

#define RAND_INT ( rand() * (rand() & 1 ? -1 : 1) )
namespace graphics {
    /* This is the constructor for a tree, it will take the radius of the
     * tree, the height of the tree */
	Tree::Tree( const Point3& pos, float tr_r, float tr_h, float to_r, float to_h ):
		Object3D( pos ){
        /* Unused variables. Legacy from when they were cones on sticks*/
        (void) to_r;
        (void) to_h;

		/* cache points for the trunk */
		static const int res = 3;

		float y=0;
		float th;

		this->m_height = tr_h;
		if( tr_h < 1 ) {
            /* If the height is less than 1
             * then this tree is too small to
             * recurse, it is a leaf */
			this->m_isleaf = true ;
		} else {
            /* This tree is not a leaf, it will have
             * a trunk and children */
			this->m_isleaf = false;
			this->m_leaf = NULL;

            /* If the tree hight is > 2.5, then it will
             * be drawn, otherwise, sizes between 1 and 2.5 are
             * not drawn. It adds more of a bush effect that way */
			if( tr_h > 2.5 ) {
                /* The tree is tall enough to be drawn */
				y = y > tr_h ? tr_h : y;

				for( th = 0; th <= 360; th += res ) {
					/* 4 points each */
					/* y is height */
					double x =  tr_r * dsin( th );
					double z =  tr_r * dcos( th );
		
                    /* Perhaps these lines were overlooked. This is
                     * calculating the NORMAL, the point is not its
                     * own normal! This IS the normal! */
					Vector3D<double> normal( x, 0, z );
		
                    /* I am adding the type PointNormal which is a Point WITH
                     * a normal */
					m_trunk_points.push_back( PointNormalD( Point3( x, 0   , z ), normal ) );
					m_trunk_points.push_back( PointNormalD( Point3( x/2, tr_h, z/2 ), normal ) );
				}
			}
	
			/* Create 3-6 random sub trees */
			int to = rand() % 3 + 3;
			for( int i = 0; i <  to ; ++ i ) {
				Translation newTrans = Translation( RAND_INT, RAND_INT, RAND_INT, rand(), 0, tr_h*1, 0  );
				Tree* tmp = new Tree( Point3(0,0,0), tr_r / 3, tr_h / 2.3, 0, 0 );
				m_sub_trees.push_back( Branch( tmp, newTrans ) );
			}
		}
	}

    /* Draws a tree. This function will draw either a trunk
     * or a leaf. If a trunk is drawn, then the tree will recusively call
     * the draw function on it's sub-trees */
	void Tree::draw( ) {
    glPushMatrix();
    glTranslated( position.getX(), position.getY(), position.getZ() );
		if( this->m_isleaf ) {
            /* If this is a leaf. i.e. it is too
             * small to continue as a branch */
			glTranslated( 0, m_height +2, 0 );
			glColor3f( 0, 0.8, 0 );

            /* Simply draw a green square */
			Point3( -2, -1, 0 ).glVertex();
			Point3(  2, -1, 0 ).glVertex();
			Point3(  1,  0.5, 0 ).glVertex();
			Point3( -1,  0.5, 0 ).glVertex();
			return ;
		}

        /* Iterator to move through the points
         * and their normals */
		vector<PointNormalD>::iterator itr;

        /* BROWN */
    	glColor3ub( 139, 69, 19 );

		glBegin( GL_QUAD_STRIP );
		for( itr = m_trunk_points.begin(); itr != m_trunk_points.end(); ++ itr ) {
			(*itr).glVertexNormal();
		}
		glEnd();

        /* A branch is a sub-tree */
		vector<Branch>::iterator itr2;

		if( ! this->m_isleaf && m_sub_trees[0].first->m_isleaf ) {
			/* One up from leaf nodes */
            /* This is for a small, but significant performance benefit. */
			glBegin( GL_QUADS );
		}

		for( itr2 = m_sub_trees.begin(); itr2 != m_sub_trees.end(); ++ itr2 ) {
            /* save translation state */
			glPushMatrix();
            /* Translate to the new position */
			(*itr2).second.glTranslate();
            /* Draw the small tree */
			(*itr2).first->draw();
            /* restore the translation state */
			glPopMatrix();
		}

		if( ! this->m_isleaf && m_sub_trees[0].first->m_isleaf ) {
			/* One up from leaf nodes */
            /* End the GL_QUADS from above */
			glEnd();
		}
    
    /* End of draw() function */
	glPopMatrix();
	}

}
