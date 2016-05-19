
#include <fstream>
#include <sstream>

#include <tests/MiniCppUnit.h>
#include <Instance.h>
#include <shop_instance.h>

class DomainTests : public TestFixture< DomainTests >
{
public:
	TEST_FIXTURE( DomainTests )
	{
		TEST_CASE( logisticsTest );
		TEST_CASE( scheduleTest );
		TEST_CASE( elevatorTest );
		TEST_CASE( temporalTest );
		TEST_CASE( multiagentTest );
		TEST_CASE( shopTest );
	}

	template < typename T >
	void checkEqual( T & prob, const std::string & file ) {
		std::ifstream f(file.c_str());
		if (!f) throw std::runtime_error(std::string("Failed to open file '") + file + "'");
		std::string s, t;
		
		while(std::getline(f, s)){
			t += s + "\n";
		}

		std::ostringstream ds;
		ds << prob;
		ASSERT_EQUALS( t, ds.str() );
		std::ofstream of("ins.txt");
		of<<ds.str();
	}

	void logisticsTest() {
		Domain dom( "domains/Log_dom.pddl" );
		Instance ins( dom, "domains/Log_ins.pddl" );

		checkEqual( dom, "tests/expected/Log_dom.pddl" );
		checkEqual( ins, "tests/expected/Log_ins.pddl" );
	}

	void scheduleTest() {
		Domain dom( "domains/Sched_dom.pddl" );
		Instance ins( dom, "domains/Sched_ins.pddl" );

		checkEqual( dom, "tests/expected/Sched_dom.pddl" );
		checkEqual( ins, "tests/expected/Sched_ins.pddl" );
	}

	void elevatorTest() {
		Domain dom( "domains/Elev_dom.pddl" );
		Instance ins( dom, "domains/Elev_ins.pddl" );

		checkEqual( dom, "tests/expected/Elev_dom.pddl" );
		checkEqual( ins, "tests/expected/Elev_ins.pddl" );
	}

	void temporalTest() {
		Domain dom( "domains/Mapana_dom.pddl" );
		Instance ins( dom, "domains/Mapana_ins.pddl" );

		checkEqual( dom, "tests/expected/Mapana_dom.pddl" );
		checkEqual( ins, "tests/expected/Mapana_ins.pddl" );
	}

	void multiagentTest() {
		Domain dom( "domains/Multilog_dom.pddl" );
		Instance ins( dom, "domains/Multilog_ins.pddl" );

		checkEqual( dom, "tests/expected/Multilog_dom.pddl" );
		checkEqual( ins, "tests/expected/Multilog_ins.pddl" );
	}

	void shopTest() {
		parser::shop::ShopDomain dom( "domains/Shop_dom"  );
		parser::shop::ShopInstance ins( dom, "domains/Shop_ins" );

		checkEqual( dom, "tests/expected/Shop_dom" );
		checkEqual( ins, "tests/expected/Shop_ins" );
	}
};

REGISTER_FIXTURE( DomainTests )

