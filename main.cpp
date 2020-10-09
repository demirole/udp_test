#include <iostream>

#include "boost/asio/io_service.hpp"
#include "boost/asio/ip/udp.hpp"
#include "boost/program_options/options_description.hpp"
#include "boost/program_options/parsers.hpp"
#include "boost/program_options/variables_map.hpp"

const auto SHORT_UDP_MESSAGE = R"json(
{"@timestamp":"2020-10-07T16:35:38.683302","ClientType":"CACT","Cluster":"REGTEST_master_dele_changes","Instance":"xentis","UserID":"UNIVERSAL-INSTITUT","application":"XsCommServer","file":"../source/bo/BODevkursFactory.cpp","function":"GetFixkurs","hostname":"pdxenlin32","level":"INFO","line":715,"logger":"AmisLogTrace","message":"End BODevkursFactory::GetFixkurs Wrong Inputparameters: rujInWaehrung_id or rdInPer_dat is NULL. Return value iRet= 1616245716","pid":7802,"scope":"static Int BODevkursFactory::GetFixkurs(const ULongInt&, const AmisDate&, ULongInt&, AmisDate&, double&)","tid":139608801146624}
)json";

const auto LONG_UDP_MESSAGE = R"json(
{"@timestamp":"2020-10-07T16:34:54.891991","ClientType":"CACT","Cluster":"REGTEST_master_dele_changes","Instance":"xentis","UserID":"UNIVERSAL-INSTITUT","application":"XsCommServer","file":"../source/appl/BOTrx.cpp","function":"executeTransaction","hostname":"pdxenlin32","level":"ERROR","line":195,"logger":"Kernel.TrxExecution","message":">>> TypedIdMismatchException caught in BOTrx::doTrx(xentis::investment_compliance::TestProcessTrx), Error message: TypedId mismatch 108300000079224A\n 0# xentis::id::detail::handleMismatchedId(xentis::Id) in /xentis/packages/XENTIS/lib/libAmisCommon.so\n 1# BTPosBewertung::getCounterAccountingPositionId() in /xentis/packages/XENTIS/lib/libAmisBT.so\n 2# xentis::business_rules::runtime::objects::PositionBase::loadCriterionValue(unsigned long, unsigned long, unsigned long&) in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 3# unsigned long& xentis::business_rules::runtime::objects::Base::getCriteriaValueByCriteria_idBrattribut_id<unsigned long>(xentis::Id const&, xentis::Id const&) in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 4# xentis::business_rules::runtime::executable::EntityPath::run(std::shared_ptr<xentis::business_rules::runtime::objects::Base> const&) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 5# xentis::business_rules::runtime::executable::AttributePath<unsigned long>::run(std::shared_ptr<xentis::business_rules::runtime::objects::Base> const&) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 6# xentis::business_rules::runtime::executable::IsNotNull<xentis::business_rules::runtime::executable::TypedBase<unsigned long> >::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRelationCreator*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 7# xentis::business_rules::runtime::executable::BOBRConditionalWhen::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRelationCreator*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 8# xentis::business_rules::runtime::executable::BOBRConditional::evaluateIf(BORuleExecutionContext&, int&, double&, xentis::business_rules::protocol::IRelationCreator*, std::vector<unsigned long, std::allocator<unsigned long> >&, std::map<unsigned long, int, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, int> > > const&, xentis::business_rules::runtime::executable::BOBRConditional::RuleObjectIteratorManager const&) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n 9# xentis::business_rules::runtime::executable::BOBRConditional::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRelationCreator*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n10# BOBRRuleBasis::getBOBRConditionalResult(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRuleNode*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n11# BOBRRuleBasis::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRuleNode*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n12# BOBRRuleBasis::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRuleNode*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n13# BOBRRuleBasis::run(BORuleExecutionContext&, double&, xentis::business_rules::protocol::IRuleNode*) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n14# BORuleExecutionSet::executeRulesByPriority(BORuleExecutionContext&, xentis::business_rules::protocol::IRootNode*, std::multimap<std::pair<int, unsigned long>, BOBRExecutionInfo const*, std::greater<std::pair<int, unsigned long> >, std::allocator<std::pair<std::pair<int, unsigned long> const, BOBRExecutionInfo const*> > > const&) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n15# BORuleExecutionSet::executeRules(BORuleExecutionContext&, xentis::business_rules::protocol::IRootNode*, std::deque<BOBRExecutionInfo, std::allocator<BOBRExecutionInfo> > const&) const in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n16# 0x00007F0DDAD5760D in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n17# xentis::business_rules::runtime::objects::WorkingMemory::executeRules(std::deque<BOBRExecutionInfo, std::allocator<BOBRExecutionInfo> > const&, xentis::business_rules::runtime::log::Result*, std::ostream*) in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n18# BORuleSession::executeRules(std::deque<BOBRExecutionInfo, std::allocator<BOBRExecutionInfo> > const&, xentis::business_rules::runtime::log::Result*, std::ostream*) in /xentis/packages/XENTIS/lib/libAmisBusinessRules.so\n19# xentis::investment_compliance::TestProcess::runAgenda(std::pair<std::shared_ptr<BORuleExecutionSet>, std::deque<BOBRExecutionInfo, std::allocator<BOBRExecutionInfo> > > const&, std::deque<BDBrpropertyassigned*, std::allocator<BDBrpropertyassigned*> > const&, std::shared_ptr<BTBewertung> const&, std::deque<xentis::id::TypedId<xentis::id::Group<1175720977720410460ul> >, std::allocator<xentis::id::TypedId<xentis::id::Group<1175720977720410460ul> > > > const&, xentis::investment_compliance::RuleExecutionTracker&, xentis::business_rules::runtime::log::Result&, BOManager&) const in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n20# xentis::investment_compliance::TestProcess::runBusinessRules(std::deque<BDBrpropertyassigned*, std::allocator<BDBrpropertyassigned*> > const&, std::pair<std::shared_ptr<BORuleExecutionSet>, std::deque<BOBRExecutionInfo, std::allocator<BOBRExecutionInfo> > > const&, std::shared_ptr<BTBewertung> const&, std::shared_ptr<xentis::license::LicenseManager>&, xentis::investment_compliance::RuleExecutionTracker&, BOManager&) in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n21# xentis::investment_compliance::TestProcess::run(BOManager&) in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n22# xentis::investment_compliance::TestProcessExecutor::icTest(BOManager&, std::shared_ptr<BTBewertung> const&, std::shared_ptr<BTBewertung> const&, std::shared_ptr<BTBewertung> const&) in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n23# xentis::investment_compliance::TestProcessTrx::run(BOManager*) in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n24# BOTrx::executeTransaction(BOTrx::ExecutionContext&, AbstractTrxProc&) in /xentis/packages/XENTIS/lib/libAmisAppl.so\n25# BOTrx::doTrx(int, AbstractTrxProc&, BOSessionContext*, std::deque<BOSyncInfo, std::allocator<BOSyncInfo> >*) in /xentis/packages/XENTIS/lib/libAmisAppl.so\n26# 0x00007F0DDF7A11B3 in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n27# boost::asio::detail::scheduler_operation::complete(void*, boost::system::error_code const&, unsigned long) in /lib64/liblogging.so.2\n28# boost::asio::detail::scheduler::do_run_one(boost::asio::detail::conditionally_enabled_mutex::scoped_lock&, boost::asio::detail::scheduler_thread_info&, boost::system::error_code const&) in /lib64/liblogging.so.2\n29# boost::asio::detail::scheduler::run(boost::system::error_code&) in /lib64/liblogging.so.2\n30# boost::asio::detail::posix_thread::func<boost::asio::thread_pool::thread_function>::run() in /xentis/packages/XENTIS/lib/libAmisInvestmentCompliance.so\n31# boost_asio_detail_posix_thread_function in /lib64/liblogging.so.2\n32# signalenv::run(void*) in /xentis/packages/XENTIS/lib/libXsPreload.so\n33# 0x00007F0DF5D46EA5 in /lib64/libpthread.so.0\n34# clone in /lib64/libc.so.6\n\nTransaction has been rolled back.\n","pid":7802,"scope":"void BOTrx::executeTransaction(BOTrx::ExecutionContext&, AbstractTrxProc&)","tid":139613595186944}
)json";

class UDPSender {
public:
  UDPSender() : m_service(), m_socket(m_service) {
    m_socket.open(boost::asio::ip::udp::v4());
  }

  void setTarget(const std::string &host, const std::string &port) {
    boost::asio::ip::udp::resolver resolver(m_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(),
                                                host, port);
    m_target = *resolver.resolve(query);
  }

  void consume(const std::string &rec) {
    m_socket.send_to(boost::asio::buffer(rec), m_target);
  }

private:
  boost::asio::io_service m_service;
  boost::asio::ip::udp::socket m_socket;
  boost::asio::ip::udp::endpoint m_target;
};

std::unique_ptr<UDPSender> process_options_and_create_sender(int argc,
                                                             char **argv) {
  using namespace boost::program_options;

  options_description desc("UDP message tester. Allowed options:");
  // clang-format off
  desc.add_options()
      ("help", "produce help message")
      ("host", value<std::string>()->default_value("localhost"), "target host")
      ("port", value<std::string>()->default_value("9000"), "target port]");
  // clang-format on

  variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help")) {
    std::cout << desc << std::endl;
    exit(0);
  }

  auto return_value = std::make_unique<UDPSender>();
  return_value->setTarget(vm["host"].as<std::string>(),
                          vm["port"].as<std::string>());
  return return_value;
}

int main(int argc, char *argv[]) {
  auto sender = process_options_and_create_sender(argc, argv);

  sender->consume(SHORT_UDP_MESSAGE);
  sender->consume(LONG_UDP_MESSAGE);
  return 0;
}
