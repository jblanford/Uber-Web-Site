UPS requires that users certify their application against a series of test
responses before access to the production servers is granted. The uc_ups module
has a 'certification mode' that can assist you in generating the files required
to pass UPS' certification process.

To begin, enable certification mode by browsing to "Administer > Store
Administration > Configuration > Shipping quote settings > Quote methods > UPS"
and selecting the checkbox titled "Certification mode". As well, be sure that
the active mode under the "Credentials" section is set to "Testing".

Next, download the latest copy of the XML developer guide documentation. It will
include the procedure required to gain production access. Login to the UPS
Developer Kit website here:
https://www.ups.com/upsdeveloperkit/downloadresource?loc=en_US

Once logged in, select and download the Shipping API. The documentation pack
should contain a document named 'Shipping Package XML Developers Guide' inside
the 'Developers Guide' folder with a section on how to certify your account for
production access.

Note that you do not need to manually capture and store the XML requests, label
images or HTML pages as noted in the UPS documentation. Putting the module in
certification mode will store all of these files for you automatically. As you
create UPS shipments from any Ubercart order, these files will created under the
sites/default/files/ups_certification folder of your website. After having
shipped and voided the shipments as specified by UPS, simply send the resulting
files in an archive to the UPS certification team.

After completing certification, remember to delete the ups_certification folder
and to disable certification mode so that the uc_ups does not continue to log
information about all your shipments. While the filenames of the generated files
would be difficult to guess, keep in mind that they are public when stored in
the site/default/files folder.
