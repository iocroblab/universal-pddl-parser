
#pragma once

#include "shop_domain.h"
#include "Instance.h"

namespace parser { namespace shop {

class ShopInstance : public Instance {
public:
	TaskVec tgoal; //goal for shop instances
	
	ShopInstance( Domain & dom ) : Instance(dom) {}

	ShopInstance( Domain & dom, const std::string & s) : ShopInstance(dom) {
		parse(s);
	}

	~ShopInstance() {
		for ( unsigned i = 0; i < tgoal.size(); ++i )
			delete tgoal[i];
	}

	void parse( const std::string &s) {
		Filereader f( s );
		name = f.parseHTNProblemName();
		f.next();

	    if ( DOMAIN_DEBUG ) std::cout << name << "\n";

		for ( ; f.getChar() != ')'; f.next() ) {
			parseInit( f );
			parseGoal( f );
		}
	}

	void parseTasks( Filereader & f, TaskVec & v ) {
			Task * t = 0;
			t = new Task( d.tasks.get( f.getToken( d.tasks ) ) );
			t->SHOPparse( f, d.types[0]->constants, d );
			v.push_back( t );
	}

	void parseGoal( Filereader & f ) override {
		f.next();
		f.assert( "(" );
		for ( f.next(); f.getChar() != ')'; f.next() ) {
			f.assert( "(" );
			parseTasks( f, tgoal );
		}
		++f.c;

		for ( unsigned i = 0; DOMAIN_DEBUG && i < goal.size(); ++i )
			std::cout << "  " << goal[i];
	}
	
	virtual void parseGround( Filereader & f, GroundVec & v ) {
		Ground * cs = 0;
		cs = new Ground( d.preds.get( f.getToken( d.preds ) ) );
		cs->SHOPparse( f, d.types[0]->constants, d );
		v.push_back( cs );
	}
	
	std::ostream& print(std::ostream& stream) const override {
		stream << "( DEFPROBLEM PROBLEM " << name << " (\n";
		for ( unsigned i = 0; i < init.size(); ++i ) {
			init[i]->PDDLPrint( stream, 1, TokenStruct< std::string >(), d );
			stream << "\n";
		}
		stream << ")\n(\n";

		for ( unsigned i = 0; i < tgoal.size(); ++i ) {
			tgoal[i]->SHOPPrint( stream, 1, TokenStruct< std::string >(), d );
			stream << "\n";
		}

		stream << ") ) )\n";
		return stream;
	}

};

} } // namespaces
