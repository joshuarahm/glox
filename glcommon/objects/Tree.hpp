#ifndef TREE_H_
#define TREE_H_

#include "graphics/common/Common.hpp"
#include "Sphere.hpp"
#include <cstdlib>

#include <vector>

namespace graphics {
	
	class Tree : public Object3D {
	public:
		Tree(const Point3& pos, float trunk_rad, float trunk_height, 
			float top_height, float top_radius );

		void draw();
	
	private:
		typedef std::pair<Tree*,Translation> Branch;
		std::vector<PointNormalD> m_trunk_points;
		std::vector<PointNormalD> m_top_points;

		/* Trees are recursive */
		std::vector< Branch > m_sub_trees;

		/* set to true if the radius
		 * is 0 */
		uint64_t m_height;
		bool m_isleaf;
		Sphere* m_leaf;
	};

}

#endif
